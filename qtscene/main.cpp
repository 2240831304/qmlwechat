#include "mainwindow.h"
#include <QApplication>
#include "tabwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow scene;
    scene.show();

    //Tabwidget widget;
    //widget.show();

    return a.exec();
}
