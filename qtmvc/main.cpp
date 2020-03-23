#include "mainwindow.h"
#include <QApplication>
#include <QTableView>
#include "tablemodelex.h"
#include "test.h"
#include <unistd.h>

#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    modeltest();
//    test11();

//    Listmodel();

//    changedata();

//    modelex modleEx;
//    QTableView view;
//    view.setModel(&modleEx);
//    view.setWindowTitle(QObject::tr("模型示例"));
//    view.resize(400,400);
    //view.show();

    QDateTime time;
    time = time.currentDateTime();
    qDebug() << time.toTime_t();

    return a.exec();
}
