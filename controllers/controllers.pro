TARGET = controller
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT += network sql xml qml
QT -= gui
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel
MOC_DIR = .obj/
OBJECTS_DIR = .obj/

include(../appbase.pri)

HEADERS += applicationcontroller.h \
    scorescontroller.h \
    participantscontroller.h
SOURCES += applicationcontroller.cpp \
    scorescontroller.cpp \
    participantscontroller.cpp
HEADERS += contestcontroller.h
SOURCES += contestcontroller.cpp
HEADERS += invitationcontroller.h
SOURCES += invitationcontroller.cpp
HEADERS += messagecontroller.h
SOURCES += messagecontroller.cpp
HEADERS += problemcontroller.h
SOURCES += problemcontroller.cpp
HEADERS += profilecontroller.h
SOURCES += profilecontroller.cpp
HEADERS += solutioncontroller.h
SOURCES += solutioncontroller.cpp
HEADERS += submitcontroller.h
SOURCES += submitcontroller.cpp
HEADERS += testcontroller.h
SOURCES += testcontroller.cpp
HEADERS += testsubmitcontroller.h
SOURCES += testsubmitcontroller.cpp
