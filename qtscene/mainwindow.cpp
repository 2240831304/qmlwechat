#include "mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include "myscene.h"
#include <QDebug>
#include "mygraphicsview.h"


MyScene *scene;
MyGraphicsView *view;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);

    buildui();
}

MainWindow::~MainWindow()
{

}


void MainWindow::buildui()
{
    view = new MyGraphicsView(this);
    view->move(50,50);
    view->setFixedSize(400,400);
    view->setSceneRect(0,0,600,400);
    view->setStyleSheet("padding: 0px; border: 0px;");

    scene = new MyScene(this);
    view->setScene(scene);
    view->centerOn(0,0);

    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(scene,SIGNAL(updateSig()),view,SLOT(updateSlot()));

}

void MainWindow::updateSlot()
{
    qDebug() << "233333333333333333====MainWindow::updateSlot()====";

    //view->scroll(10,0);
    //view->centerOn(90,0);

    //view->update();
}
