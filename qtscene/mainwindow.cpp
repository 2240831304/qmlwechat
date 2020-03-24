#include "mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include "myscene.h"

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
    QGraphicsView *view = new QGraphicsView(this);
    view->move(50,50);
    view->setFixedSize(600,400);
    view->setSceneRect(0,0,600,400);
    view->setStyleSheet("padding: 0px; border: 0px;");

    MyScene *scene = new MyScene(this);
    view->setScene(scene);

}
