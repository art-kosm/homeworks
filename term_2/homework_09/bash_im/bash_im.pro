QT       += core gui network xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bash_im
TEMPLATE = app


SOURCES += main.cpp\
        mainWindow.cpp

HEADERS  += mainWindow.h

FORMS    += mainWindow.ui
