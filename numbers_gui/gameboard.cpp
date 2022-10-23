/*
#############################################################################
# COMP.CS.110 Programming 2                                                 #
# Project 4: 2048                                                           #
# File: gameboard.cpp                                                       #
# Description: Describes the internal structure of the gameboard in         #
#              the game.                                                    #                                           #
#############################################################################
*/

#include "gameboard.hh"
#include <iostream>

GameBoard::GameBoard()
{
}

GameBoard::~GameBoard()
{
    for(unsigned int y = 0; y < board_.size(); ++y)
    {
        for(unsigned int x = 0; x < board_.at(y).size(); ++x)
        {
            delete board_.at(x).at(y);
            board_.at(x).at(y) = nullptr;
        }
    }
}

void GameBoard::init_empty()
{
    std::vector<NumberTile*> row;
    for( int i = 0; i < SIZE; ++i)
    {
        row.push_back(nullptr);
    }
    for( int i = 0; i < SIZE; ++i)
    {
        board_.push_back(row);
    }
}

void GameBoard::fill(int seed)
{
    randomEng_.seed(seed);
    distribution_ = std::uniform_int_distribution<int>(0, SIZE - 1);

    // Wiping out the first random number (which is almost almost 0)
    distribution_(randomEng_);

    for( auto y = 0; y < SIZE; ++y )
    {
        for( auto x = 0; x < SIZE; ++x )
        {
            board_.at(y).at(x) = new NumberTile(0, std::make_pair(y, x), this);
        }
    }

    for( int i = 0 ; i < SIZE ; ++i )
    {
        new_value();
    }
}

void GameBoard::new_value(bool check_if_empty)
{
    if( check_if_empty and is_full() ){
        // So that we will not be stuck in a forever loop
        return;
    }
    int random_x = 0;
    int random_y = 0;
    do
    {
        random_x = distribution_(randomEng_);
        random_y = distribution_(randomEng_);
    } while( not board_.at(random_y).at(random_x)->new_value(NEW_VALUE) );
}

// Not used in the gui version
void GameBoard::print() const
{
    for( auto y : board_ )
    {
        std::cout << std::string(PRINT_WIDTH * SIZE + 1, '-') << std::endl;
        for( auto x : y )
        {
            x->print(PRINT_WIDTH);
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::string(PRINT_WIDTH * SIZE + 1, '-') << std::endl;
}

bool GameBoard::move(Coords dir, int goal)
{
    bool has_won = false;
    for( unsigned y = 0; y < board_.size(); ++y )
    {
        for( unsigned x = 0; x < board_.front().size(); ++x )
        {
            int directed_y = dir.first > 0 ? board_.size() - y - 1 : y;
            int directed_x = dir.second > 0 ? board_.back().size() - x - 1 : x;
            if( board_.at(directed_y).at(directed_x)->move(dir, goal) )
            {
                has_won = true;
            }
        }
    }
    for( auto &row : board_ )
    {
        for( auto &tile : row )
        {
            tile->reset_turn();
        }
    }
    return has_won;
}

NumberTile* GameBoard::get_item(Coords coords)
{
    return board_.at(coords.first).at(coords.second);
}

// Returns all values saved on the board in a two-dimensional vector
std::vector<std::vector<int>> GameBoard::get_value()
{
    std::vector<std::vector<int>> tile_values_;

    for( auto y : board_ )
    {
        std::vector<int> line;
        for( auto x : y )
        {
            int value = x->return_tile_value();
            line.push_back(value);
        }
        tile_values_.push_back(line);
    }
    return tile_values_;
}

void GameBoard::reset_board()
{
    for( auto y : board_ )
    {
        for( auto x : y )
        {
            x->reset_tile_value();
        }
    }
    players_score_ = 0;
}

// Sums the current score with the score gained on one move and saves it to the
// variable player_score_.
// Param merged_value, int: Points gained with one move
void GameBoard::add_score(int merged_value)
{
    players_score_ += merged_value;
}

// Returns the score for using it in mainwindow
int GameBoard::get_score()
{
    return players_score_;
}

// Searches tiles with non-zero value and stores them to a vector. Then
// randomly selects one tile for emptying and calls a method to empty it.
void GameBoard::empty_random_square()
{
    std::vector<std::vector<int>> tiles_with_nonzero_values;
    for (int y = 0; y < SIZE; ++y)
    {
       for (int x = 0; x < SIZE; ++x)
       {
           if (board_.at(y).at(x)->return_tile_value() != 0)
           {
               std::vector<int> coordinates;
               coordinates.push_back(x);
               coordinates.push_back(y);
               tiles_with_nonzero_values.push_back(coordinates);
           }
       }
    }
    int selected = rand() % tiles_with_nonzero_values.size();
    std::vector<int> selected_coordinates = tiles_with_nonzero_values.at
            (selected);
    board_.at(selected_coordinates.at(1)).at(selected_coordinates.at(0))->
            reset_tile_value();
}

bool GameBoard::is_full() const
{
    for( auto y : board_ )
    {
        for( auto x : y )
        {
            if( x->is_empty() )
            {
                return false;
            }
        }
    }
    return true;
}
