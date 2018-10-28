 TARGET = testproblem
 TEMPLATE = app
 CONFIG += console debug c++11
 CONFIG -= app_bundle
 QT += network sql testlib
 QT -= gui
 DEFINES += TF_DLL
 INCLUDEPATH += ../..
 LIBS += -L../../lib -lmodel
 include(../../appbase.pri)
 SOURCES = testproblem.cpp      # Specifying the file name