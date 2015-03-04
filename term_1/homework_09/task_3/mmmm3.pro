TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    graph.cpp \
    stack.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    graph.h \
    stack.h

QMAKE_CXXFLAGS += -std=c++11
