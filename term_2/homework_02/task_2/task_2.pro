TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    linkedliststack.cpp \
    recursivestack.cpp \
    computePostfix.cpp \
    transformToPostfix.cpp \
    calculator.cpp

HEADERS += \
    stack.h \
    linkedliststack.h \
    recursivestack.h \
    computePostfix.h \
    transformToPostfix.h \
    calculator.h

QMAKE_CXXFLAGS += -std=c++11
