TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    quicksortsorter.cpp \
    heapsortsorter.cpp \
    stupidsorter.cpp \
    bogosortsorter.cpp \
    sorter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    sorter.h \
    quicksortsorter.h \
    heapsortsorter.h \
    stupidsorter.h \
    bogosortsorter.h

