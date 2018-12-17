TARGET = helper
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT += xml qml core
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += /usr/include/boost
DEPENDPATH  +=
LIBS += -L/usr/include/boost -lboost_system -lboost_thread
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
HEADERS += profilevalidator.h
SOURCES += profilevalidator.cpp
HEADERS += profileeditvalidator.h
SOURCES += profileeditvalidator.cpp
HEADERS += tester.h
SOURCES += tester.cpp
