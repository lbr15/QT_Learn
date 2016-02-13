#-------------------------------------------------
#
# Project created by QtCreator 2016-02-06T12:15:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PLC_Signal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plcbasic.cpp \
    ladsignaltbl.cpp

HEADERS  += mainwindow.h \
    def.h \
    ladsignaltbl.h \
    plcbasic.h

FORMS    += mainwindow.ui
