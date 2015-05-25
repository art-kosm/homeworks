QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    computePostfix.cpp \
    transformToPostfix.cpp \
    calculator.cpp \
    linkedListStack.cpp \
    recursiveStack.cpp

HEADERS += \
    stack.h \
    computePostfix.h \
    transformToPostfix.h \
    calculator.h \
    calculatorTest.h \
    linkedListStack.h \
    linkedListStackTest.h \
    recursiveStack.h \
    recursiveStackTest.h

QMAKE_CXXFLAGS += -std=c++11
