TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    consoleprinter.cpp \
    fileprinter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arrayprinter.h \
    consoleprinter.h \
    fileprinter.h

QMAKE_CXXFLAGS += -std=c++11
