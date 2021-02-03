TEMPLATE = app
CONFIG += console c++2a
CONFIG += c++2a
CONFIG += c++latest
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        furniture.cpp \
        main.cpp \
        menu.cpp

HEADERS += \
    furniture.h \
    menu.h

QMAKE_CXXFLAGS += -std=c++2a
QMAKE_LFLAGS +=  -std=c++2a

QMAKE_CC = gcc-10
QMAKE_CXX = g++-10
