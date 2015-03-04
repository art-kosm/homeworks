TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stack.cpp \
    computePostfix.cpp \
    transformToPostfix.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stack.h \
    computePostfix.h \
    transformToPostfix.h

QMAKE_CXXFLAGS += --std=c++11
