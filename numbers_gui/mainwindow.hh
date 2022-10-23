/*
#############################################################################
# COMP.CS.110 Programming 2                                                 #
# Project 4: 2048                                                           #
# File: mainwindow.hh                                                       #
# Description: Handles the graphic user interface of game.                  #                     #                                        #
#############################################################################
*/

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "gameboard.hh"
#include "numbertile.hh"
#include <QMainWindow>
#include <QTimer>
#include <QString>
#include <QTextBrowser>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QFile>
#include <QChar>
#include <QThread>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Handles the timer.
    void onSecTimer();

    // Handles the images used in the game.
    void images();

    // These below handle the users selections when playing the game. More
    // info in cpp file.
    void onStartButtonClicked();
    void onResetButtonClicked();
    void on_seedSpinBox_valueChanged(int arg1);
    void onUpButtonClicked();
    void onDownButtonClicked();
    void onRightButtonClicked();
    void onLeftButtonClicked();
    void on_goalNumberSpinBox_valueChanged(int arg1);
    void on_nameLineEdit_editingFinished();
    void on_clearSpinBox_valueChanged(int arg1);
    void on_pausePushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer_;

    // Enabling using gameboard class
    GameBoard gameboard_;

    // These are for making the size of the grid suitable for ui
    int margin = 3;
    int label_width = 337/SIZE;
    int label_height = 337/SIZE;

    // Variables for saving game settings and feature selections
    bool is_first_game = true;
    QString player_name_ = "";
    bool won_or_lost = false;
    int seed_value_ = 0;
    int goal_value_ = 2048;
    int clearing_interval_ = 0;
    int move_counter_ = 0;
    bool paused = false;

    // Images used in the game
    QPixmap up_image_;
    QPixmap down_image_;
    QPixmap left_image_;
    QPixmap right_image_;
    std::vector<QPixmap> board_images_;

    std::vector<std::vector<QLabel*>> grid_;

    // This creates the game board
    void initGrid();
    // Hadles moves and winning and losing examination
    void gameplay(Coords coords);
    // Displays board on ui
    void displayBoard();
    // Hadles operations needed for winning and losing
    void gameWon();
    void gameLost();
    // Saves scores to structures from text file and organizes them
    void organizeScores();
    // Displays score boar
    void printScoreBoard(std::vector<std::vector<std::string>> scores,
                           std::vector<int> points_of_players);
    // Saves new score
    void saveNewScore();
    // Checks that the name only contains letters and numbers
    void checkName(QString name);
    // Split function
    std::vector<std::string> splitLine(QString& line);
};
#endif // MAINWINDOW_HH
