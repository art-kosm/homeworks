TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    listscomparator.cpp \
    linkedlist.cpp \
    sortedset.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    listscomparator.h \
    linkedlist.h \
    sortedset.h

QMAKE_CXXFLAGS += -std=c++11
