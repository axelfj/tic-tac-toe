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
    startwindow.cpp \
    qlabel_event.cpp \
    minmax.cpp \
    winnerdialog.cpp \
    winnerdialoghuman.cpp

HEADERS  += \
    startwindow.h \
    qlabel_event.h \
    minmax.h \
    winnerdialog.h \
    winnerdialoghuman.h

FORMS    += \
    startwindow.ui \
    winnerdialog.ui \
    winnerdialoghuman.ui

RESOURCES += \
    Res.qrc
