QT       += testlib gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hashtable
TEMPLATE = app


SOURCES += main.cpp\
    hashtable.cpp \
    linkedList.cpp \
    generalTab.cpp \
    hashFunctionTab.cpp \
    mainWindow.cpp \
    statisticsTab.cpp

HEADERS  += \
    hashtable.h \
    generalTab.h \
    hashFunctionTab.h \
    linkedList.h \
    mainWindow.h \
    statisticsTab.h \
    linkedListTest.h \
    hashtableTest.h

FORMS    += \
    mainWindow.ui

QMAKE_CXXFLAGS += --std=c++11
