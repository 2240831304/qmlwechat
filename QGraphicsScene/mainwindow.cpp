#include "mainwindow.h"

#include <QGraphicsView>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(800,600);
    setupui();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupui()
{
    QGraphicsView *view = new QGraphicsView(this);
    //QGraphicsScene *scene = new QGraphicsScene(this);
    //view->setScene(scene);


}
