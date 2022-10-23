/*
#############################################################################
# COMP.CS.110 Programming 2                                                 #
# Project 4: 2048                                                           #
# File: main.cpp                                                            #
# Description: main module                                                  #                                           #
#############################################################################
*/

#include "mainwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
