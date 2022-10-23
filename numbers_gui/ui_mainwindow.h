/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLCDNumber *lcdNumberMin;
    QLCDNumber *lcdNumberSec;
    QLabel *label;
    QLabel *label_2;
    QPushButton *startPushButton;
    QPushButton *resetPushButton;
    QPushButton *closePushButton;
    QTextBrowser *textBrowser;
    QSpinBox *seedSpinBox;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *goalNumberSpinBox;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *goalNumberLabel;
    QPushButton *upPushButton;
    QPushButton *downPushButton;
    QPushButton *rightPushButton;
    QPushButton *leftPushButton;
    QLabel *label_7;
    QSpinBox *clearSpinBox;
    QLabel *label_8;
    QLabel *scoreLabel;
    QLabel *label_9;
    QTextBrowser *scoreBoardTextBrowser;
    QLabel *label_10;
    QLineEdit *nameLineEdit;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pausePushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(992, 348);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 251, 156);\n"
"background-color: rgb(255, 230, 248);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lcdNumberMin = new QLCDNumber(centralwidget);
        lcdNumberMin->setObjectName(QString::fromUtf8("lcdNumberMin"));
        lcdNumberMin->setGeometry(QRect(620, 10, 64, 23));
        lcdNumberMin->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 139, 43);\n"
"color: rgb(0, 0, 0);"));
        lcdNumberSec = new QLCDNumber(centralwidget);
        lcdNumberSec->setObjectName(QString::fromUtf8("lcdNumberSec"));
        lcdNumberSec->setGeometry(QRect(620, 40, 64, 23));
        lcdNumberSec->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 139, 43);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(690, 10, 31, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(690, 40, 21, 20));
        startPushButton = new QPushButton(centralwidget);
        startPushButton->setObjectName(QString::fromUtf8("startPushButton"));
        startPushButton->setGeometry(QRect(620, 110, 84, 28));
        startPushButton->setStyleSheet(QString::fromUtf8("color: rgb(221, 139, 43);\n"
"background-color: rgb(221, 139, 43);\n"
"color: rgb(0, 0, 0);"));
        resetPushButton = new QPushButton(centralwidget);
        resetPushButton->setObjectName(QString::fromUtf8("resetPushButton"));
        resetPushButton->setGeometry(QRect(620, 150, 84, 28));
        resetPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 139, 43);\n"
"color: rgb(0, 0, 0);"));
        closePushButton = new QPushButton(centralwidget);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));
        closePushButton->setGeometry(QRect(620, 190, 84, 28));
        closePushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 139, 43);"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(530, 230, 171, 91));
        textBrowser->setStyleSheet(QString::fromUtf8("border-color: rgb(226, 251, 156);"));
        seedSpinBox = new QSpinBox(centralwidget);
        seedSpinBox->setObjectName(QString::fromUtf8("seedSpinBox"));
        seedSpinBox->setGeometry(QRect(530, 60, 45, 29));
        seedSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 139, 43);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 60, 31, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 140, 21, 31));
        goalNumberSpinBox = new QSpinBox(centralwidget);
        goalNumberSpinBox->setObjectName(QString::fromUtf8("goalNumberSpinBox"));
        goalNumberSpinBox->setGeometry(QRect(460, 120, 45, 29));
        goalNumberSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 139, 43);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(400, 90, 91, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(520, 150, 21, 20));
        goalNumberLabel = new QLabel(centralwidget);
        goalNumberLabel->setObjectName(QString::fromUtf8("goalNumberLabel"));
        goalNumberLabel->setGeometry(QRect(550, 150, 51, 20));
        upPushButton = new QPushButton(centralwidget);
        upPushButton->setObjectName(QString::fromUtf8("upPushButton"));
        upPushButton->setGeometry(QRect(420, 230, 31, 31));
        downPushButton = new QPushButton(centralwidget);
        downPushButton->setObjectName(QString::fromUtf8("downPushButton"));
        downPushButton->setGeometry(QRect(420, 290, 31, 31));
        rightPushButton = new QPushButton(centralwidget);
        rightPushButton->setObjectName(QString::fromUtf8("rightPushButton"));
        rightPushButton->setGeometry(QRect(450, 260, 31, 31));
        leftPushButton = new QPushButton(centralwidget);
        leftPushButton->setObjectName(QString::fromUtf8("leftPushButton"));
        leftPushButton->setGeometry(QRect(390, 260, 31, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(440, 10, 81, 20));
        clearSpinBox = new QSpinBox(centralwidget);
        clearSpinBox->setObjectName(QString::fromUtf8("clearSpinBox"));
        clearSpinBox->setGeometry(QRect(530, 10, 45, 29));
        clearSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 139, 43);"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(400, 190, 63, 20));
        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setGeometry(QRect(480, 190, 63, 20));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(750, 10, 121, 21));
        scoreBoardTextBrowser = new QTextBrowser(centralwidget);
        scoreBoardTextBrowser->setObjectName(QString::fromUtf8("scoreBoardTextBrowser"));
        scoreBoardTextBrowser->setGeometry(QRect(740, 40, 231, 221));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(730, 300, 81, 20));
        nameLineEdit = new QLineEdit(centralwidget);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(810, 290, 161, 31));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(580, 10, 16, 20));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(480, 30, 41, 20));
        pausePushButton = new QPushButton(centralwidget);
        pausePushButton->setObjectName(QString::fromUtf8("pausePushButton"));
        pausePushButton->setGeometry(QRect(620, 70, 84, 28));
        pausePushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(221, 139, 43);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 992, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(closePushButton, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "min", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "sec", nullptr));
        startPushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        resetPushButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        closePushButton->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Seed", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:20pt;\">2</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Goal number", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        goalNumberLabel->setText(QString());
        upPushButton->setText(QString());
        downPushButton->setText(QString());
        rightPushButton->setText(QString());
        leftPushButton->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Clear every", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        scoreLabel->setText(QString());
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">All time scores</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Nickname:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "th", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "move", nullptr));
        pausePushButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
