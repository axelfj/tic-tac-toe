#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T17:54:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tictactoe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    startwindow.cpp \
    qlabel_event.cpp

HEADERS  += mainwindow.h \
    startwindow.h \
    qlabel_event.h

FORMS    += mainwindow.ui \
    startwindow.ui

RESOURCES += \
    Res.qrc
