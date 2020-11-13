#-------------------------------------------------
#
# Project created by QtCreator 2020-03-24T10:16:52
#
#-------------------------------------------------

QT       += core gui
QT += quick
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtscene
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    myitem.cpp \
    myscene.cpp \
    data.cpp \
    tabwidget.cpp \
    myqtabbar.cpp

HEADERS += \
        mainwindow.h \
    myitem.h \
    myscene.h \
    data.h \
    tabwidget.h \
    myqtabbar.h

RESOURCES += \
    tabs.qrc \
    qtsence.qrc
