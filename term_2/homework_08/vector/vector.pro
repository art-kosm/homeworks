QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp

HEADERS += \
    vector.h \
    vectorTest.h

QMAKE_CXXFLAGS += -std=c++11
