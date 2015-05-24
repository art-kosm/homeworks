QT       += testlib
QT       -= gui

CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    linkedList.cpp \
    listsComparator.cpp \
    sortedSet.cpp

HEADERS += \
    linkedList.h \
    listsComparator.h \
    sortedSet.h \
    listsComparatorTest.h \
    linkedListTest.h \
    sortedSetTest.h

QMAKE_CXXFLAGS += -std=c++11
