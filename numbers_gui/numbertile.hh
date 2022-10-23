/*
#############################################################################
# COMP.CS.110 Programming 2                                                 #
# Project 4: 2048                                                           #
# File: numbertile.hh                                                       #
# Description: Describes a single number tile in the game.                  #                      #                                          #
#############################################################################
*/

#ifndef NUMBERTILE_HH
#define NUMBERTILE_HH

#include <vector>
#include <iostream>

using Coords = std::pair<int, int>;

// Forward declaration, to avoid circular include's
class GameBoard;

class NumberTile
{
public:
    // Constructor
    NumberTile(int value, Coords coords, GameBoard* board);

    // Destructor
    ~NumberTile();

    // Prints the number tile.
    void print(int width);

    // Moves the number tile in the given direction and merges it, if possible.
    // Returns true, if the player won the game, i.e. if the goal value was
    // reached, otherwise returns false.
    bool move(Coords direction, int goal_val);

    // Sets a new value for an empty number tile.
    // Returns true, if a new value was set, otherwise returns false.
    bool new_value(int new_val);

    // Returns true, if the number tile is empty, i.e. if it has the value 0.
    bool is_empty();

    // Sets the value of is_merged_ as false.
    void reset_turn();

    // Returns tile value
    int return_tile_value();

    // Sets the tile value to zero
    void reset_tile_value();


private:
    // Value in the number tile
    int value_;

    // Coordinates of the number tile
    Coords coords_;

    // Pointer to the gameboard, where the number tile lies
    GameBoard* board_;

    // Tells if the number is merged or not,
    // can be true only temporarily during moves
    bool is_merged_;

    // Returns true, if the given coordinates are on the gameboard,
    // otherwise returns false.
    bool is_on_board(Coords coords);

};

#endif // NUMBERTILE_HH
