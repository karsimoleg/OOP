#-------------------------------------------------
#
# Project created by QtCreator 2018-11-11T20:13:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sea_battle
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    battlefield.cpp \
    ship.cpp \
    myfield.cpp \
    enemyfield.cpp \
    gameover_window.cpp

HEADERS  += mainwindow.h \
    battlefield.h \
    ship.h \
    myfield.h \
    enemyfield.h \
    gameover_window.h

FORMS    += mainwindow.ui \
    gameover_window.ui
