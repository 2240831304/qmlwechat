#include "mygraphicsview.h"
#include <QDebug>

MyGraphicsView::MyGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{

    InitCentOnPos.setX(200);
    InitCentOnPos.setY(200);

    MoveCentOnPos = InitCentOnPos;
}


void MyGraphicsView::updateSlot()
{
    qDebug() << "333333333333333333 MyGraphicsView::updateSlot =========";

    //centerOn(250,200);

    //update();

}


void MyGraphicsView::moveRangeSlot(int rangeX,int rangeY)
{
    qDebug() << "2222222222222222222===============" << rangeX;

    int x = MoveCentOnPos.x() - rangeX;

    if(x < InitCentOnPos.x()){
        x = InitCentOnPos.x();
    }

    if(x > 450){
        x = 450;
    }


    MoveCentOnPos.setX(x);

    centerOn(MoveCentOnPos);
}
