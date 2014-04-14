#-------------------------------------------------
#
# Project created by QtCreator 2013-05-31T14:23:59
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = networkNote
OTHER_FILES+= \
networkNote.rc
RC_FILE = \
    networkNote.rc

TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editpatr.cpp \
    mainmenubar.cpp \
    connectdatabase.cpp \
    login.cpp \
    sign_in_widget.cpp \
    mainfunction.cpp \
    notedatamodel.cpp

HEADERS  += mainwindow.h \
    editpatr.h \
    mainmenubar.h \
    connectdatabase.h \
    login.h \
    sign_in_widget.h \
    mainfunction.h \
    notedatamodel.h

FORMS    += mainwindow.ui \
    editpatr.ui \
    login.ui \
    sign_in_widget.ui

RESOURCES += \
    qrc/button.qrc

OTHER_FILES += \
    networkNote.rc
