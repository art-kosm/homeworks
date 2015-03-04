TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    binarysearchtree.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    binarysearchtree.h

QMAKE_CXXFLAGS += -std=c++11
