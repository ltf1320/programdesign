#-------------------------------------------------
#
# Project created by QtCreator 2013-08-07T01:03:51
#
#-------------------------------------------------

QT       += core gui
QT  +=  printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mditextedit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mditextedit.cpp \
    findfileform.cpp

HEADERS  += mainwindow.h \
    mditextedit.h \
    findfileform.h

FORMS    += mainwindow.ui \
    findfileform.ui

RESOURCES += \
    mainwindow.qrc \
    touxiang.qrc \
    touxiang.qrc
