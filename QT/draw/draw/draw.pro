#-------------------------------------------------
#
# Project created by QtCreator 2013-11-23T21:50:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = draw
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagewidget.cpp \
    graph.cpp \
    factory.cpp

HEADERS  += mainwindow.h \
    imagewidget.h \
    graph.h \
    factory.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
