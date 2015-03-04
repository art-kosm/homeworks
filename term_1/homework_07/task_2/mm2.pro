TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    string.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    string.h

QMAKE_CXXFLAGS += -std=c++11
