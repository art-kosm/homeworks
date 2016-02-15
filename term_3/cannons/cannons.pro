#-------------------------------------------------
#
# Project created by QtCreator 2016-01-31T13:00:57
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cannons
TEMPLATE = app


SOURCES += main.cpp\
    gameArea.cpp \
    shell.cpp \
    mainWindow.cpp \
    cannon.cpp

HEADERS  += \
    gameArea.h \
    shell.h \
    mainWindow.h \
    cannon.h \
    messageExchanger.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=c++11
DESTDIR = $$PWD

DISTFILES +=
