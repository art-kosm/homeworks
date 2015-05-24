QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    filePrinter.cpp \
    consolePrinter.cpp \
    arrayPrinter.cpp

HEADERS += \
    arrayPrinter.h \
    consolePrinter.h \
    filePrinter.h \
    filePrinterTest.h

QMAKE_CXXFLAGS += -std=c++11
