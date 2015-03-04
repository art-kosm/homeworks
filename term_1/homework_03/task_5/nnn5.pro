TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sortedList.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sortedList.h

QMAKE_CXXFLAGS += -std=c++11
