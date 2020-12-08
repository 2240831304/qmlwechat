
#include "myscene.h"
#include "myitem.h"
#include <QDebug>
#include <QVector>
#include <QGraphicsSceneMouseEvent>

struct ItemPosition
{
    int startX;
    int startY;
};


QVector<MyItem *>ItemVector;
QVector<ItemPosition> ItemPosVector;

int focusIndex = 0;

MyScene::MyScene(QObject *parent)
    :QGraphicsScene(parent)
{

    dataObjec = new data;

    init();
#if 1
    buildTest();
#else
    buildUI();
#endif

    connect(this,SIGNAL(focusItemChanged(QGraphicsItem *, QGraphicsItem *, Qt::FocusReason)),
            this,SLOT(focusItemChangedSlot(QGraphicsItem *, QGraphicsItem *, Qt::FocusReason)));

}

MyScene::~MyScene()
{
    if(dataObjec){
        delete dataObjec;
        dataObjec = nullptr;
    }

    QVector<MyItem *>::iterator pt = ItemVector.begin();
    for(;pt != ItemVector.end();++pt){
        delete *pt;
        *pt = NULL;
    }
    ItemVector.clear();

    ItemPosVector.clear();
}

void MyScene::init()
{
    showItemNumber = 5;
    itemWidth = 120;
    itemHeight = 120;
    isMousePress = false;
}

void MyScene::clear()
{

}

void MyScene::buildTest()
{
    dataObjec->loadAppData();
    totleAppNum = dataObjec->getAppNumber();

#if 0
    QGraphicsRectItem *rectItem = this->addRect(QRectF(200, 100, 200, 200));
    rectItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsFocusable);
    QPen pen = rectItem->pen();
    pen.setWidth(2);
    pen.setColor(QColor(111, 111, 111));
    rectItem->setPen(pen);
    rectItem->setBrush(QColor(111, 111, 111, 100));
#endif

    ItemPosition temPos;

    MyItem *itemOne = new MyItem;
    itemOne->setpos(0,100);
    itemOne->setSize(itemWidth,itemHeight);
    ItemVector.push_back(itemOne);
    itemOne->setName(dataObjec->getData(0).appName);

    temPos.startX = 0;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    MyItem *itemTwo = new MyItem;
    itemTwo->setpos(120,100);
    itemTwo->setSize(itemWidth,itemHeight);
    ItemVector.push_back(itemTwo);
    itemTwo->setName(dataObjec->getData(1).appName);

    temPos.startX = 120;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    MyItem *itemThree = new MyItem;
    itemThree->setpos(240,100);
    itemThree->setSize(itemWidth,itemHeight);
    itemThree->setFocusStatus(true);

    setFocusItem(itemThree);

    focusIndex = 2;

    ItemVector.push_back(itemThree);
    itemThree->setName(dataObjec->getData(2).appName);

    temPos.startX = 240;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    MyItem *itemFore = new MyItem;
    itemFore->setpos(360,100);
    itemFore->setSize(itemWidth,itemHeight);
    ItemVector.push_back(itemFore);
    itemFore->setName(dataObjec->getData(3).appName);

    temPos.startX = 360;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    MyItem *itemFive = new MyItem;
    itemFive->setpos(480,100);
    itemFive->setSize(itemWidth,itemHeight);
    ItemVector.push_back(itemFive);
    itemFive->setName(dataObjec->getData(4).appName);

    temPos.startX = 480;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    addItem(itemOne);
    addItem(itemTwo);
    addItem(itemThree);
    addItem(itemFore);
    addItem(itemFive);

    showFirstAppIndex = 0;
    showEndAppIndex = 4;
}

void MyScene::buildUI()
{

}


void MyScene::focusItemChangedSlot(QGraphicsItem *newFocusItem, QGraphicsItem *oldFocusItem, Qt::FocusReason reason)
{
    qDebug() << "===============点击图元================";
}

void MyScene::drawBackground( QPainter * painter, const QRectF & rect )
{

}


void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton){
        //向左滑动
        if(mouseEvent->screenPos().x() < pressedPos.x()){
            showFirstAppIndex += 1;
            showEndAppIndex += 1;
        }else{
            //向右滑动

        }
    }

}


void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton){
        isMousePress = true;
        pressedPos = mouseEvent->screenPos();
    }
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    isMousePress = false;

    qDebug() << "==============move before===============" << focusIndex;

    //向左滑动
    if(mouseEvent->screenPos().x() < pressedPos.x()){

        int tempFocusIndex = focusIndex;
        focusIndex += 1;

        if(focusIndex >= totleAppNum){
            focusIndex -= 1;
            return;
        }

        showFirstAppIndex += 1;
        showEndAppIndex += 1;
        int tempXPt = 0;

        for(int i = 0; i<ItemVector.size();++i){
            tempXPt = ItemVector[i]->getItemXpos() - 120;
            ItemVector[i]->setpos(tempXPt,100);

            if(i == tempFocusIndex){
                ItemVector[i]->setFocusStatus(false);
            }else if(i == focusIndex){
                ItemVector[i]->setFocusStatus(true);
            }

        }


    }else{
        //向右滑动
        int tempFocusIndex = focusIndex;
        focusIndex -= 1;

        if(focusIndex < 0){
            focusIndex += 1;
            return;
        }

        showFirstAppIndex -= 1;
        showEndAppIndex -= 1;
        int tempXPt = 0;

        for(int i = 0; i<ItemVector.size();++i){
            tempXPt = ItemVector[i]->getItemXpos() + 120;
            ItemVector[i]->setpos(tempXPt,100);

            if(i == tempFocusIndex){
                ItemVector[i]->setFocusStatus(false);
            }else if(i == focusIndex){
                ItemVector[i]->setFocusStatus(true);
            }

        }

    }

    qDebug() << "==============move finished===============" << focusIndex;

    emit updateSig();
}
