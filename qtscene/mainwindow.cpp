#include "mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include "myscene.h"
#include <QDebug>

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
    view = new QGraphicsView(this);
    view->move(50,50);
    view->setFixedSize(400,400);
    view->setSceneRect(0,0,400,400);
    view->setStyleSheet("padding: 0px; border: 0px;");

    MyScene *scene = new MyScene(this);
    view->setScene(scene);
    connect(scene,SIGNAL(updateSig()),this,SLOT(updateSlot()));

}

void MainWindow::updateSlot()
{
    view->update();
}
