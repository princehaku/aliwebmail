#-------------------------------------------------
#
# Project created by QtCreator 2013-05-24T20:50:50
#
#-------------------------------------------------

QT       += core gui webkit network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = aliwebmail
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myqnetworkaccessmanager.cpp

HEADERS  += mainwindow.h \
    myqnetworkaccessmanager.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    loadcomplete.js \
    1.cer
