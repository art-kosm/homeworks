QT       += testlib gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

SOURCES += main.cpp\
    hashtable.cpp \
    linkedList.cpp \
    generalTab.cpp \
    hashFunctionTab.cpp \
    mainWindow.cpp \
    statisticsTab.cpp \
    hashSimple.cpp \
    hashRS.cpp \
    hashLY.cpp

HEADERS  += \
    hashtable.h \
    generalTab.h \
    hashFunctionTab.h \
    linkedList.h \
    mainWindow.h \
    statisticsTab.h \
    linkedListTest.h \
    hashtableTest.h \
    hashFunction.h \
    hashSimple.h \
    hashRS.h \
    hashLY.h

FORMS    += \
    mainWindow.ui

QMAKE_CXXFLAGS += --std=c++11
