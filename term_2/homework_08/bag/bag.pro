QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    bag.cpp

HEADERS += \
    bag.h \
    bagTest.h

QMAKE_CXXFLAGS += -std=c++11
