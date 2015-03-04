TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    phonelist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    phonelist.h

QMAKE_CXXFLAGS += -std=c++11
