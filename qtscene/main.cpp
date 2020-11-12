#include "mainwindow.h"
#include <QApplication>
#include "tabwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    Tabwidget widget;
    widget.show();

    return a.exec();
}
