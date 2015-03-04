TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    avltree.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    avltree.h

QMAKE_CXXFLAGS += -std=c++11
