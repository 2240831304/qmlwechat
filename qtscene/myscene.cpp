
#include "myscene.h"
#include "myitem.h"
#include <QDebug>
#include <QVector>
#include <QPainter>
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
    QGraphicsRectItem *rectItem = this->addRect(QRectF(10, 10, 100, 100));
    rectItem->setFlag(QGraphicsItem::ItemIsSelectable,true);
    rectItem->setFlag(QGraphicsItem::ItemIsMovable,true);
    rectItem->setFlag(QGraphicsItem::ItemIsFocusable,true);

    QPen pen = rectItem->pen();
    pen.setWidth(2);
    pen.setColor(QColor(111, 111, 111));
    rectItem->setPen(pen);
    rectItem->setBrush(QColor(111, 111, 111, 100));
#endif

    ItemPosition temPos;

    MyItem *itemOne = new MyItem;
    connect(itemOne,SIGNAL(doubleSig(QString)),this,SLOT(ItemDoubleClickedSlot(QString)));
    itemOne->setpos(0,100);
    itemOne->setSize(itemWidth,itemHeight);
    ItemVector.push_back(itemOne);
    itemOne->setName(dataObjec->getData(0).appName);

    temPos.startX = 0;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    MyItem *itemTwo = new MyItem;
    connect(itemTwo,SIGNAL(doubleSig(QString)),this,SLOT(ItemDoubleClickedSlot(QString)));
    itemTwo->setpos(120,100);
    itemTwo->setSize(itemWidth,itemHeight);
    ItemVector.push_back(itemTwo);
    itemTwo->setName(dataObjec->getData(1).appName);

    temPos.startX = 120;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    MyItem *itemThree = new MyItem;
    connect(itemThree,SIGNAL(doubleSig(QString)),this,SLOT(ItemDoubleClickedSlot(QString)));
    itemThree->setpos(240,100);
    itemThree->setSize(itemWidth,itemHeight);
    itemThree->setFocusStatus(true);

    focusIndex = 2;

    ItemVector.push_back(itemThree);
    itemThree->setName(dataObjec->getData(2).appName);

    temPos.startX = 240;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    MyItem *itemFore = new MyItem;
    connect(itemFore,SIGNAL(doubleSig(QString)),this,SLOT(ItemDoubleClickedSlot(QString)));
    itemFore->setpos(360,100);
    itemFore->setSize(itemWidth,itemHeight);
    ItemVector.push_back(itemFore);
    itemFore->setName(dataObjec->getData(3).appName);

    temPos.startX = 360;
    temPos.startY = 100;
    ItemPosVector.push_back(temPos);

    MyItem *itemFive = new MyItem;
    connect(itemFive,SIGNAL(doubleSig(QString)),this,SLOT(ItemDoubleClickedSlot(QString)));
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

void MyScene::ItemDoubleClickedSlot(QString name)
{
    qDebug() << "==============MyScene::ItemDoubleClickedSlot name ===" << name;
}


void MyScene::drawBackground( QPainter * painter, const QRectF & rect )
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(QBrush(QColor(192,192,192)));
    painter->drawRect(rect);
}


#if 0

void MyScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << "================MyScene::mouseDoubleClickEvent=========";
    QGraphicsScene::mouseDoubleClickEvent(event);
}
#endif


#if 1

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::LeftButton){
        isMousePress = true;
        pressedPos = mouseEvent->scenePos();
        movePos = mouseEvent->scenePos();
    }

    QGraphicsScene::mousePressEvent(mouseEvent); // 将点击事件向下传递到item中
}


void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(isMousePress) {
        int tempXPt = 0;
        int grap = mouseEvent->scenePos().x() - movePos.x();
        //qDebug() << "===============MyScene::mouseMoveEvent move grape==== " << grap;
        //qDebug() << "===============MyScene::mouseMoveEvent move gloable Xpos==== " << mouseEvent->screenPos().x();
        //qDebug() << "===============MyScene::mouseMoveEvent move scene Xpos==== " << mouseEvent->scenePos().x();
        //qDebug() << "===============MyScene::mouseMoveEvent move scene Ypos==== " << mouseEvent->scenePos().y();

        //向左滑动
        if(mouseEvent->scenePos().x() < pressedPos.x()){
            showFirstAppIndex += 1;
            showEndAppIndex += 1;

            tempXPt = mouseEvent->scenePos().x() + grap;

        }else{
            //向右滑动
            tempXPt = mouseEvent->scenePos().x() + grap;
        }

        for(int i = 0; i<ItemVector.size();++i){
            tempXPt = ItemVector[i]->getItemXpos() + grap;
            ItemVector[i]->setpos(tempXPt,100);

        }

        movePos = mouseEvent->scenePos();
        //qDebug() << "===========MyScene::mouseMoveEvent===========";
        emit updateSig();
    }

    QGraphicsScene::mouseMoveEvent(mouseEvent);
}


void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    isMousePress = false;

    qDebug() << "==============move before===============" << focusIndex;

    int grap = mouseEvent->scenePos().x() - movePos.x();
    //向左滑动
    if(mouseEvent->scenePos().x() < pressedPos.x()){

        int tempFocusIndex = focusIndex;
        focusIndex += 1;

        if(focusIndex >= totleAppNum){
            focusIndex -= 1;
        }

        showFirstAppIndex += 1;
        showEndAppIndex += 1;
        int tempXPt = 0;

        int firstItemXpos = ItemVector[4]->getItemXpos() + grap;
        if(firstItemXpos < 280){
            grap = 280 - firstItemXpos;
        }

        for(int i = 0; i<ItemVector.size();++i){
            tempXPt = ItemVector[i]->getItemXpos() + grap;
            ItemVector[i]->setpos(tempXPt,100);

            if(i == tempFocusIndex){
                ItemVector[i]->setFocusStatus(false);
            }else if(i == focusIndex){
                ItemVector[i]->setFocusStatus(true);
            }
        }
        if(tempFocusIndex == focusIndex){
            ItemVector[focusIndex]->setFocusStatus(true);
        }

        qDebug() << "333333333333333333333333=" << ItemVector[4]->getItemXpos();
        qDebug() << "333333333333333333333333=" << ItemVector[3]->getItemXpos();

        emit updateSig();
    }else if(mouseEvent->scenePos().x() > pressedPos.x()){
        //向右滑动
        int tempFocusIndex = focusIndex;
        focusIndex -= 1;

        if(focusIndex < 0){
            focusIndex += 1;
        }

        showFirstAppIndex -= 1;
        showEndAppIndex -= 1;
        int tempXPt = 0;

        int firstItemXpos = ItemVector[0]->getItemXpos() + grap;
        if(firstItemXpos > 0){
            grap = 0 - firstItemXpos;
        }

        for(int i = 0; i<ItemVector.size();++i){
            tempXPt = ItemVector[i]->getItemXpos() + grap;
            ItemVector[i]->setpos(tempXPt,100);

            if(i == tempFocusIndex){
                ItemVector[i]->setFocusStatus(false);
            }else if(i == focusIndex){
                ItemVector[i]->setFocusStatus(true);
            }
        }
        if(tempFocusIndex == focusIndex){
            ItemVector[focusIndex]->setFocusStatus(true);
        }

        emit updateSig();
    }

    qDebug() << "==============move finished===============" << focusIndex;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);

}

#endif
