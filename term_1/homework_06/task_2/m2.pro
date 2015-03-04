TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    binaryexpressiontree.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    binaryexpressiontree.h

QMAKE_CXXFLAGS += -std=c++11
