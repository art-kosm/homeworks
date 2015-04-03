QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

TARGET = untitled

INCLUDEPATH += $$PWD

SOURCES += \
    main.cpp \
    priorityqueue.cpp

HEADERS += \
    priorityqueue.h \
    prorityqueuetest.h

QMAKE_CXXFLAGS += -std=c++11
