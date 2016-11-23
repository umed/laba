#-------------------------------------------------
#
# Project created by QtCreator 2016-11-04T00:26:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#QMAKE_CXXFLAGS += -std=gnu++0x

TARGET = laba
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calcwidget.cpp \
    algorithm.cpp \
    rutishauseralgorithm.cpp \
    baurzamelzonalgorithm.cpp \
    rpnalgorithm.cpp

HEADERS  += mainwindow.h \
    calcwidget.h \
    algorithm.h \
    rutishauseralgorithm.h \
    baurzamelzonalgorithm.h \
    rpnalgorithm.h

FORMS    += mainwindow.ui \
    calcwidget.ui
