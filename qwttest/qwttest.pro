#-------------------------------------------------
#
# Project created by QtCreator 2019-02-27T16:53:50
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qwttest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawplanpie.cpp \
    drawsolidpie.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    drawplanpie.h \
    drawsolidpie.h \
    qcustomplot.h


INCLUDEPATH += /usr/local/qwt/include/
LIBS += -L"/usr/local/qwt/lib/" -lqwt
