
#include "myitem.h"
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QRect>
#include <QPainter>
#include <QDebug>
#include <QGraphicsScene>

MyItem::MyItem()
{
    //setAcceptDrops(true);
    isFocus = false;

    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

//    this->setFlag(QGraphicsItem::ItemIsSelectable);
//    this->setAcceptedMouseButtons(Qt::LeftButton);
      //this->setAcceptHoverEvents(true);//重写hover事件需添加
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

int MyItem::getItemXpos()
{
    return xpos;
}

int MyItem::getItemYpos()
{
    return ypos;
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

void MyItem::drawBackground ( QPainter * painter, const QRectF & rect )
{
//    painter->setPen(Qt::NoPen);
//    painter->setBrush(QBrush(QColor(0,0,255)));
//    QRectF rect12 = boundingRect();
//    painter->drawRect(rect12);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    if(pixName.isEmpty())
        return;

    QPen pen(Qt::black);
    painter->setPen(pen);

    QRectF rect = boundingRect();
    painter->setBrush(QBrush(QColor(0,0,255)));
    painter->drawRect(rect.x(),rect.y(),rect.width(),rect.height());

    int textHeight = (height - rect.height() ) / 2 -2;
    QRect rectTemp(rect.x(),rect.y() + rect.height() +2 ,rect.width(),textHeight);

    painter->setPen(QPen(QColor(255,48,48)));
    painter->drawText(rectTemp, pixName, QTextOption(Qt::AlignHCenter | Qt::AlignVCenter));

    qDebug() << "@@@@@@@@@@@MyItem::paint========" << pixName;

    //碰撞检测
    if(!scene()->collidingItems(this).isEmpty() ){
        painter->setBrush(QBrush(QColor(255,215,0)));
        painter->drawRect(rect.x(),rect.y(),rect.width(),rect.height());
    }


}


void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "=============图元点击事件产生===============";

    //QGraphicsItem::mousePressEvent(event);
}

// Alt+拖拽：进行缩放  移动
void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    //QGraphicsItem::mouseMoveEvent(event);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "=============图元点击，释放事件完成===============";

    //QGraphicsItem::mouseReleaseEvent(event);
}

void MyItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "------------MyItem::mouseDoubleClickEvent-------";
    emit doubleSig(pixName);
}

QVariant MyItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    qDebug() << "44444444444444444MyItem::itemChange======";
    if (change == ItemPositionChange && scene()) {
            // value is the new position.
            QPointF newPos = value.toPointF();
            QRectF rect = scene()->sceneRect();
            if (!rect.contains(newPos)) {
                // Keep the item inside the scene rect.
                newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
                newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
                return newPos;
            }
        }
        return QGraphicsItem::itemChange(change, value);
}
