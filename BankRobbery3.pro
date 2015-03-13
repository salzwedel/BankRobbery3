#-------------------------------------------------
#
# Project created by QtCreator 2015-01-31T18:48:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BankRobbery3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myplayer.cpp \
    bullet.cpp \
    badguy.cpp \
    game.cpp \
    hostage.cpp \
    endings.cpp

HEADERS  += mainwindow.h \
    myplayer.h \
    bullet.h \
    badguy.h \
    game.h \
    hostage.h \
    endings.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
