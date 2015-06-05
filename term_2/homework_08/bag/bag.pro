QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    bag.cpp \
    tree.cpp

HEADERS += \
    bag.h \
    tree.h \
    treeTest.h

QMAKE_CXXFLAGS += -std=c++11
