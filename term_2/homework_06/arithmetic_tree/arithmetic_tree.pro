QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    tree.cpp \
    number.cpp \
    operatorAdd.cpp \
    operatorDiv.cpp \
    operatorMul.cpp \
    operatorSub.cpp \
    calculator.cpp \
    operator.cpp \
    treeBuilder.cpp

HEADERS += \
    operand.h \
    tree.h \
    number.h \
    operator.h \
    operatorAdd.h \
    operatorDiv.h \
    operatorMul.h \
    operatorSub.h \
    calculator.h \
    treeBuilder.h \
    operatorTest.h \
    numberTest.h \
    operandTest.h \
    treeTest.h \
    treeBuilderTest.h

QMAKE_CXXFLAGS += -std=c++11
