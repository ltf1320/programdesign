
QT +=core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = screenshot
HEADERS = screenShotWindow.h \
          fullScreenWidget.h

SOURCES = main.cpp \ 
          screenShotWindow.cpp \
          fullScreenWidget.cpp 

DESTDIR = ./bin

#temp-directory sources
OBJECTS_DIR = ./.objtmp
MOC_DIR = ./.moctmp
UI_DIR  += ./.uitmp
