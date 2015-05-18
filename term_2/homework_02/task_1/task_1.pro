QT       += testlib
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += \
    main.cpp \
    doublyLinkedList.cpp \
    singlyLinkedList.cpp

HEADERS += \
    doublyLinkedList.h \
    doublyLinkedListTest.h \
    linkedList.h \
    singlyLinkedList.h \
    singlyLinkedListTest.h

QMAKE_CXXFLAGS += -std=c++11
