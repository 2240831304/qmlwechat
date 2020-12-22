#include "mygraphicsview.h"
#include <QDebug>

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{

}


void MyGraphicsView::updateSlot()
{
    qDebug() << "333333333333333333 MyGraphicsView::updateSlot =========";

    scrollContentsBy(100,0);
    //update();

}
