QT       += testlib
QT       -= gui

CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    numberClass.cpp

HEADERS += \
    sharedPointer.h \
    linkedList.h \
    numberClass.h

QMAKE_CXXFLAGS += -std=c++11
