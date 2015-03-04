TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hashtable.cpp \
    linkedList.cpp \
    string.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hashtable.h \
    linkedList.h \
    string.h

QMAKE_CXXFLAGS += --std=c++11
