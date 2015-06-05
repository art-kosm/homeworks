QT       += core gui testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app


SOURCES += main.cpp\
        mainWindow.cpp \
    ticTacToeGame.cpp

HEADERS  += mainWindow.h \
    ticTacToeGameTest.h \
    ticTacToeGame.h

FORMS    += mainWindow.ui
