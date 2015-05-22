QT       += testlib gui

CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    uniqueList.cpp

HEADERS += \
    uniqueList.h \
    uniqueListTest.h \
    valueAlreadyExistsException.h \
    valueNotFoundException.h \
    valueNotFoundExceptionTest.h \
    valueAlreadyExistsExceptionTest.h

QMAKE_CXXFLAGS += --std=c++11
