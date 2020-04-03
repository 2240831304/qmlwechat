
#include "myitem.h"
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QRect>
#include <QDebug>

MyItem::MyItem()
{
    //setAcceptDrops(true);
    //setFlags(ItemIsSelectable | ItemIsMovable);
    isFocus = false;
}

void MyItem::setPixmap(const QString &pixPath)
{
    picPath = pixPath;
}

void MyItem::setName(const QString &name)
{
    pixName = name;
}

void MyItem::setpos(int x,int y)
{
    xpos = x;
    ypos = y;
}

void MyItem::setSize(int xwidth,int yheight)
{
    width = xwidth;
    height = yheight;
}

void  MyItem::setFocusStatus(bool flag)
{
    isFocus = flag;
}


QRectF MyItem::boundingRect() const
{
    if(isFocus){
        int widthTemp = width * 2 / 3;
        int heightTemp = height * 2 / 3 ;
        int xtemp = xpos + width / 6;
        int ytemp = ypos + height / 6;
        return QRectF(xtemp,ytemp,widthTemp,heightTemp);
    } else {
        int widthTemp = width / 2;
        int heightTemp = height / 2;
        int xtemp = xpos + width / 4;
        int ytemp = ypos + height / 4;
        return QRectF(xtemp,ytemp,widthTemp,heightTemp);
    }
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    if(pixName.isEmpty())
        return;

    QPen pen(Qt::black);
    painter->setPen(pen);

    QRectF rect = boundingRect();
    painter->drawRect(rect.x(),rect.y(),rect.width(),rect.height());

    int textHeight = (height - rect.height() ) / 2 -2;
    QRect rectTemp(rect.x(),rect.y() + rect.height() +2 ,rect.width(),textHeight);
    painter->drawText(rectTemp, pixName, QTextOption(Qt::AlignHCenter | Qt::AlignVCenter));

}
