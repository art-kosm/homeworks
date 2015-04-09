QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    sorter.cpp \
    bogosortSorter.cpp \
    heapsortSorter.cpp \
    quicksortSorter.cpp \
    stupidSorter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sorter.h \
    bogosortSorter.h \
    bogosortSorterTest.h \
    heapsortSorter.h \
    quicksortSorter.h \
    stupidSorter.h \
    quicksortSorterTest.h \
    heapsortSorterTest.h \
    stupidSorterTest.h

