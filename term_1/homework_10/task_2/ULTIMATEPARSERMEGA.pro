TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lexer.cpp \
    parser.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    lexer.h \
    parser.h

