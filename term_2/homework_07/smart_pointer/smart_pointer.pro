QT       += testlib
QT       -= gui

CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp

HEADERS += \
    sharedPointer.h \
    numberClass.h \
    smartPointerTest.h

QMAKE_CXXFLAGS += -std=c++11
