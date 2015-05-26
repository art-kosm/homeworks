QT       += testlib gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = advanced_calculator_ui
TEMPLATE = app


SOURCES += main.cpp\
    calculator.cpp \
    mainWindow.cpp

HEADERS  += \
    calculator.h \
    mainWindow.h \
    calculatorTest.h

FORMS    += \
    mainWindow.ui
