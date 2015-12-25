TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += testlib

SOURCES += main.cpp \
    computer.cpp \
    network.cpp

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    computer.h \
    network.h \
    networkTest.h
