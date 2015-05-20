TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

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
    treeBuilder.h

QMAKE_CXXFLAGS += -std=c++11
