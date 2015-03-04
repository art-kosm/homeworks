TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    doublylinkedlist.cpp \
    singlylinkedlist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    doublylinkedlist.h \
    singlylinkedlist.h \
    linkedlist.h

QMAKE_CXXFLAGS += -std=c++11
