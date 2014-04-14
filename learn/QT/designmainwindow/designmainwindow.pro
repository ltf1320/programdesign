#-------------------------------------------------
#
# Project created by QtCreator 2013-08-04T22:16:38
#
#-------------------------------------------------

QT       += core gui

QT  +=  printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = designmainwindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    findfileform.cpp

HEADERS  += mainwindow.h \
    findfileform.h

FORMS    += mainwindow.ui \
    findfileform.ui

RESOURCES += \
    mainwindow.qrc \
    touxiang.qrc
