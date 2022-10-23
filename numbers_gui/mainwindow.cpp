/*
#############################################################################
# COMP.CS.110 Programming 2                                                 #
# Project 4: 2048                                                           #
# File: mainwindow.cpp                                                      #
# Description: Handles the graphic user interface of game.                  #                                           #
#############################################################################
*/

#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <math.h>

// The constructor creates the interface and sets default and minimum values
// for components in the interface. It also calls for methods that handle the
// pictures, constructing the grid and show the scoreboard. Connections and
// timer are also implemented here.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Happy birthday 2048");
    images();
    initGrid();
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &MainWindow::onSecTimer);

    connect(ui->startPushButton, &QPushButton::clicked, this,
            &MainWindow::onStartButtonClicked);
    connect(ui->resetPushButton, &QPushButton::clicked, this,
            &MainWindow::onResetButtonClicked);

    connect(ui->upPushButton, &QPushButton::clicked, this,
            &MainWindow::onUpButtonClicked);
    connect(ui->downPushButton, &QPushButton::clicked, this,
            &MainWindow::onDownButtonClicked);
    connect(ui->rightPushButton, &QPushButton::clicked, this,
            &MainWindow::onRightButtonClicked);
    connect(ui->leftPushButton, &QPushButton::clicked, this,
            &MainWindow::onLeftButtonClicked);

    ui->upPushButton->setDisabled(true);
    ui->downPushButton->setDisabled(true);
    ui->leftPushButton->setDisabled(true);
    ui->rightPushButton->setDisabled(true);

    ui->resetPushButton->setCheckable(true);
    ui->resetPushButton->setChecked(true);
    ui->resetPushButton->setDisabled(true);

    ui->pausePushButton->setCheckable(true);
    ui->pausePushButton->setChecked(true);
    ui->pausePushButton->setDisabled(true);

    ui->goalNumberSpinBox->setValue(11);
    ui->goalNumberSpinBox->setMinimum(2);

    ui->upPushButton->setIcon(up_image_);
    ui->downPushButton->setIcon(down_image_);
    ui->leftPushButton->setIcon(left_image_);
    ui->rightPushButton->setIcon(right_image_);

    ui->scoreLabel->setText(QString::number(0));
    organizeScores();
}

// The destructor deletes the user interface, the timer and created labels that
// form the game board
MainWindow::~MainWindow()
{
    delete ui;
    delete timer_;
    for(unsigned int y = 0; y < grid_.size(); ++y)
    {
        for(unsigned int x = 0; x < grid_.at(y).size(); ++x)
        {
            delete grid_.at(x).at(y);
            grid_.at(x).at(y) = nullptr;
        }
    }
}

// This hadles and displays the timer
void MainWindow::onSecTimer()
{
    int seconds = ui->lcdNumberSec->intValue();
    int minutes = ui->lcdNumberMin->intValue();
    ++seconds;

    if (seconds == 60)
    {
        seconds = 0;
        ++minutes;
    }

    ui->lcdNumberSec->display(seconds);
    ui->lcdNumberMin->display(minutes);
}

// This saves the seed value after selection
void MainWindow::on_seedSpinBox_valueChanged(int arg1)
{
    if (arg1 == 0)
    {
        seed_value_ = time(NULL);
    }
    else
    {
        seed_value_ = arg1;
    }
}

// This handles the operations that are needed when the game is started.
// Moving buttons are activated and other buttons disabled. This starts the
// timer and fills and displays the game board.
void MainWindow::onStartButtonClicked()
{
    on_nameLineEdit_editingFinished();
    timer_->start(1000);

    ui->resetPushButton->setDisabled(false);
    ui->resetPushButton->setChecked(false);
    ui->resetPushButton->setCheckable(false);

    ui->pausePushButton->setDisabled(false);
    ui->pausePushButton->setChecked(false);
    ui->pausePushButton->setCheckable(false);

    // This checks whether the game is first and new objects need to be created
    // for the gameboard
    if (is_first_game)
    {
        gameboard_.init_empty();
    }

    gameboard_.fill(seed_value_);
    displayBoard();

    ui->startPushButton->setCheckable(true);
    ui->startPushButton->setChecked(true);
    ui->startPushButton->setDisabled(true);

    ui->clearSpinBox->setDisabled(true);
    ui->goalNumberSpinBox->setDisabled(true);
    ui->seedSpinBox->setDisabled(true);
    ui->nameLineEdit->setDisabled(true);

    ui->upPushButton->setDisabled(false);
    ui->downPushButton->setDisabled(false);
    ui->leftPushButton->setDisabled(false);
    ui->rightPushButton->setDisabled(false);

    if (player_name_ == "")
    {
        ui->nameLineEdit->setText("Guest");
    }
}

// This handles reseting the game. When reseted, score is saved, timer stopped
// and backroung color changed back to default. The game board is also reseted
// and displayed after that. Made it possible to change setting through push
// buttons, spin boxes and line edit. Timer is reseted as well. Values such
// as score and goal value returned to default.
void MainWindow::onResetButtonClicked()
{
    saveNewScore();
    this->setStyleSheet("background-color: rgb(255, 230, 248);");

    if (!won_or_lost)
    {
        ui->scoreBoardTextBrowser->clear();
        organizeScores();
    }
    timer_->stop();

    gameboard_.reset_board();
    displayBoard();

    ui->startPushButton->setDisabled(false);
    ui->startPushButton->setChecked(false);
    ui->startPushButton->setCheckable(false);

    ui->goalNumberSpinBox->setDisabled(false);
    ui->seedSpinBox->setDisabled(false);
    ui->clearSpinBox->setDisabled(false);
    ui->nameLineEdit->setDisabled(false);

    ui->upPushButton->setDisabled(true);
    ui->downPushButton->setDisabled(true);
    ui->leftPushButton->setDisabled(true);
    ui->rightPushButton->setDisabled(true);

    ui->pausePushButton->setCheckable(true);
    ui->pausePushButton->setChecked(true);
    ui->pausePushButton->setDisabled(true);

    ui->lcdNumberMin->display(0);
    ui->lcdNumberSec->display(0);

    // Clears the text informing about winning or losing
    ui->textBrowser->clear();

    ui->goalNumberSpinBox->setValue(11);

    // The game can not be first after reseting
    is_first_game = false;

    // Starts counting moves from zero again
    move_counter_ = 0;

    ui->scoreLabel->setText(QString::number(0));
}

// These four methods handle moving the board. When a push button is clicked
// calls for the method that moves the board with the correct direction as a
// parameter.
void MainWindow::onUpButtonClicked()
{
    gameplay(UP);
}

void MainWindow::onDownButtonClicked()
{
    gameplay(DOWN);
}

void MainWindow::onRightButtonClicked()
{
    gameplay(RIGHT);
}

void MainWindow::onLeftButtonClicked()
{
    gameplay(LEFT);
}

// This creates the grid for the first game with labels and saves pointers
// to the labels in a vector
void MainWindow::initGrid()
{
    for (int y = 0; y < SIZE; ++y)
    {
        std::vector<QLabel*> line;
        for (int x = 0; x < SIZE; ++x)
        {
             QLabel* label = new QLabel(this);
             line.push_back(label);
             label->setGeometry(2*margin + x*label_width, 2*margin +
                                y*label_height, label_width, label_height);
             label->setStyleSheet("border: 1px solid black;");
        }
        grid_.push_back(line);
    }
}

// This handles with moving the game board. It calls for the move method,
// and the method that adds new value to the grid. This also examines the
// winning and losing situations. Displays the new board after move and displays
// new score.
// Param direction, coords: the direction where to the board is moved
void MainWindow::gameplay(Coords direction)
{
    // Move counter increases whenever the board is moved
    ++move_counter_;
    // This checks wheter a square needs to be emptied with this move
    if (clearing_interval_ != 0)
    {
        if (move_counter_ % clearing_interval_ == 0)
        {
            gameboard_.empty_random_square();
        }
    }
    gameboard_.new_value(false);

    if (gameboard_.move(direction, goal_value_))
    {
        ++move_counter_;
        displayBoard();
        gameWon();
    }
    else if (gameboard_.is_full())
    {
        ++move_counter_;
        displayBoard();
        gameLost();
    }   

    displayBoard();
    ui->scoreLabel->setText(QString::number(gameboard_.get_score()));
}

// This method is for displaying the board. This goes through every value on
// board and displays the corresponding picture for each value.
void MainWindow::displayBoard()
{
    std::vector<std::vector<int>> all_values;
    all_values = gameboard_.get_value();
    for (int y=0; y < SIZE; ++y)
    {
        for (int x=0; x < SIZE; ++x)
        {
            int value = all_values.at(y).at(x);
            if (value > 2048)
            {
                grid_.at(y).at(x)->setText(QString::number(value));
            }
            else
            {
                int power;
                if (value == 0)
                {
                    power = 0;
                }
                else
                {
                    power = log(value)/log(2);
                }
                grid_.at(y).at(x)->setPixmap(board_images_.at(power));
            }
        }
    }
}

// This handles winning the game. When the game is won, background color changes
// timer stops, score is saved and user informed about winning. Makes pause
// and direction push buttons disabled.
void MainWindow::gameWon()
{
    this->setStyleSheet("background-color: green;");
    timer_->stop();

    ui->textBrowser->setText("Great! You won!");
    saveNewScore();
    ui->scoreBoardTextBrowser->clear();
    organizeScores();

    // bool for checking if the game has ended
    won_or_lost = true;

    ui->pausePushButton->setCheckable(true);
    ui->pausePushButton->setChecked(true);
    ui->pausePushButton->setDisabled(true);

    ui->upPushButton->setDisabled(true);
    ui->downPushButton->setDisabled(true);
    ui->leftPushButton->setDisabled(true);
    ui->rightPushButton->setDisabled(true);
}

// This handles losing the game. When the game is won, background color changes,
// timer stops, score is saved and user informed about losing. Makes pause
// and direction push buttons disabled.
void MainWindow::gameLost()
{
    this->setStyleSheet("background-color: red;");
    timer_->stop();
    ui->textBrowser->setText("The board is full, you lost!");
    saveNewScore();
    ui->scoreBoardTextBrowser->clear();
    organizeScores();

    won_or_lost = true;

    ui->pausePushButton->setCheckable(true);
    ui->pausePushButton->setChecked(true);
    ui->pausePushButton->setDisabled(true);

    ui->upPushButton->setDisabled(true);
    ui->downPushButton->setDisabled(true);
    ui->leftPushButton->setDisabled(true);
    ui->rightPushButton->setDisabled(true);
}

// This reads the scores saved to the text file, organizes them and calls for
// a method to print them
void MainWindow::organizeScores()
{
    QFile text_file("scoreboard.txt");
    text_file.open(QIODevice::ReadOnly);

    // Checking for errors in opening the file
    if (! text_file.isOpen())
    {
        ui->scoreBoardTextBrowser->append("Error in finding the scores, "
                                           "sorry!");
    }
    else
    {
        // For saving lines of the text file
        std::vector<std::vector<std::string>> scores;
        // For saving points as intengers
        std::vector<int> points_of_players;
        // Goes throung the file and saves info to structures above
        while (! text_file.atEnd())
        {
            QString line = text_file.readLine();
            std::vector<std::string> score = splitLine(line);
            int number = stoi(score.at(1));

            if (std::find(points_of_players.begin(), points_of_players.end()
                          , number) == points_of_players.end())
            {
                points_of_players.push_back(number);
            }

            sort(points_of_players.begin(), points_of_players.end());
            reverse(points_of_players.begin(), points_of_players.end());
            scores.push_back(score);
        }

        printScoreBoard(scores, points_of_players);
    }

    text_file.close();
}

// This displays the all time score board.
// Param scores, vec<vec<str>>: Vector containing vectors containing one line
// of the text file where the scores are saved
// Param points_of_players, vec<int>: Vector containing once every score that
// has appeared in the game
void MainWindow::printScoreBoard(std::vector<std::vector<std::string>> scores,
                                 std::vector<int> points_of_players)
{
    // For each score saved, searches names of players with the score and
    // displays the information on the scoreboard text browser
    for (int value : points_of_players)
    {
        for (std::vector player_points : scores)
        {
            if (stoi(player_points.at(1)) == value)
            {
                std::string info;
                info.append(player_points.at(0));
                info.append(" ");
                info.append(player_points.at(1));
                QString qinfo = QString::fromStdString(info);
                ui->scoreBoardTextBrowser->append(qinfo);
            }
        }
    }
}

// When game ends or is reseted, saves the score to the text file with the name
// inputted to line edit. If name is not inputted, replaces it with Guest
void MainWindow::saveNewScore()
{
    QFile text_file("scoreboard.txt");
    text_file.open(QIODevice::WriteOnly | QIODevice::Append);

    if (player_name_ == "")
    {
        player_name_ = "Guest";
    }

    QTextStream out(&text_file);
    out << player_name_ << ":" << gameboard_.get_score() << "\n";
    text_file.close();
}

// This checks the name user has inputted to avoind problems when handling the
// name. Check that every character in the name belongs to allowed characters
// and if not, the incorrect character is removed form the name. Saves the
// checked name to the variable player_name_.
// Param name, QStr: The nick name that user has inputted
void MainWindow::checkName(QString name)
{
    std::vector<char> allowed_chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                                       'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
                                       'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                                       'y', 'x', '0', '1', '2', '3', '4', '5',
                                       '6', '7', '8', '9'};

    // Allowing also upper case letters
    for (int i = 0; i < 26; ++i)
    {
        allowed_chars.push_back(toupper(allowed_chars.at(i)));
    }

    QString checked_name;
    for (QChar mark : name)
    {
        if (count(allowed_chars.begin(), allowed_chars.end(), mark.toLatin1())
                == 1)
        {
            checked_name.append(mark);
        }
    }

    player_name_ = checked_name;
}

// This is a split function that is used when handling the information saved
// to the scoreboard.txt file
// Param line, QStr: Line of the text file
// Return, vec<str>: Vector containing the name and points saved on one row of
// text file
std::vector<std::string> MainWindow::splitLine(QString &line)
{
    std::vector<std::string> result;
    QString delim = ":";
    int middle = line.indexOf(delim);
    std::string line_ = line.toStdString();
    std::string name = line_.substr(0,middle);
    std::string points = line_.substr(middle+1, line_.length()-1);
    result.push_back(name);
    result.push_back(points);

    return result;
}

// Calculates the goal value according to users selection of power of two.
// Saves this value and displays it in the label.
// Param arg1, int: The power that user has chosen
void MainWindow::on_goalNumberSpinBox_valueChanged(int arg1)
{
    goal_value_ = pow(2,arg1);
    ui->goalNumberLabel->setText(QString::number(goal_value_));
}

// This handles the pictures that are used in the game. Saves pictures to
// variables and scales them.
void MainWindow::images()
{
    const std::string PREFIX(":/new/prefix1/resources/");
    const std::string SUFFIX(".png");

    std::string up_file = PREFIX + "up" + SUFFIX;
    QPixmap up_image(QString::fromStdString(up_file));

    std::string down_file = PREFIX + "down" + SUFFIX;
    QPixmap down_image(QString::fromStdString(down_file));

    std::string left_file = PREFIX + "left" + SUFFIX;
    QPixmap left_image(QString::fromStdString(left_file));

    std::string right_file = PREFIX + "right" + SUFFIX;
    QPixmap right_image(QString::fromStdString(right_file));

    // Pictures withing the grid are saved with numbers as names so for
    // loop is handy for saving them
    for (int i = 0; i < 12; ++i)
    {
        std::string picture_name = std::to_string(i);
        std::string file = PREFIX + picture_name + SUFFIX;
        QPixmap picture(QString::fromStdString(file));
        board_images_.push_back(picture.scaled(340/SIZE,340/SIZE));
    }

    up_image_ = up_image.scaled(100,100);
    down_image_ = down_image.scaled(100,100);
    left_image_ = left_image.scaled(100,100);
    right_image_ = right_image.scaled(100,100);
}

// Gets the inputted name from line edit and calls for method to check it
void MainWindow::on_nameLineEdit_editingFinished()
{
    checkName(ui->nameLineEdit->text());
}

// Saves the selected value for clearing interval.
// Param arg1, int: The value that user has selected
void MainWindow::on_clearSpinBox_valueChanged(int arg1)
{
    clearing_interval_ = arg1;
}

// This handles the pausing feature. Since the same button is used to pause and
// restart, there is a bool that check if the game is alredy paused. When pause
// is clicked moving buttons are disables, timer stopped and user informed in
// the text browser. When restarted changed these thing back.
void MainWindow::on_pausePushButton_clicked()
{
    if (!paused)
    {
        paused = true;
        timer_->stop();

        ui->upPushButton->setDisabled(true);
        ui->downPushButton->setDisabled(true);
        ui->leftPushButton->setDisabled(true);
        ui->rightPushButton->setDisabled(true);

        ui->textBrowser->append("The game is now paused.");
    }
    else
    {
        paused = false;
        timer_->start();

        ui->upPushButton->setDisabled(false);
        ui->downPushButton->setDisabled(false);
        ui->leftPushButton->setDisabled(false);
        ui->rightPushButton->setDisabled(false);

        ui->textBrowser->clear();
    }
}
