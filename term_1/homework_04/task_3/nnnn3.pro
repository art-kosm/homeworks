TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    stack.cpp \
    computePostfix.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    stack.h \
    computePostfix.h

QMAKE_CXXFLAGS += -std=c++11
