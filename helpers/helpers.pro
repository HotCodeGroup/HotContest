TARGET = helper
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT += xml qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH +=
DEPENDPATH  +=
LIBS +=
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
HEADERS += profilevalidator.h
SOURCES += profilevalidator.cpp
HEADERS += profileeditvalidator.h
SOURCES += profileeditvalidator.cpp
