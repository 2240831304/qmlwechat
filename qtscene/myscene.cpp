
#include "myscene.h"
#include "myitem.h"
#include <QDebug>
#include <QVector>

QVector<MyItem *>ItemVector;

MyScene::MyScene(QObject *parent)
    :QGraphicsScene(parent)
{

#if 1
    buildTest();
#else
    buildUI();
#endif

}

void MyScene::buildTest()
{
    MyItem *itemOne = new MyItem;
    itemOne->setpos(0,100);
    itemOne->setSize(120,120);
    ItemVector.push_back(itemOne);
    //itemOne->setName("one");

    MyItem *itemTwo = new MyItem;
    itemTwo->setpos(120,100);
    itemTwo->setSize(120,120);
    ItemVector.push_back(itemTwo);
    //itemTwo->setName("two");

    MyItem *itemThree = new MyItem;
    itemThree->setpos(240,100);
    itemThree->setSize(120,120);
    itemThree->setFocusStatus(true);
    ItemVector.push_back(itemThree);
    //itemThree->setName("three");

    MyItem *itemFore = new MyItem;
    itemFore->setpos(360,100);
    itemFore->setSize(120,120);
    ItemVector.push_back(itemFore);
    //itemFore->setName("fore");

    MyItem *itemFive = new MyItem;
    itemFive->setpos(480,100);
    itemFive->setSize(120,120);
    ItemVector.push_back(itemFive);
    //itemFive->setName("five");

    addItem(itemOne);
    addItem(itemTwo);
    addItem(itemThree);
    addItem(itemFore);
    addItem(itemFive);
}

void MyScene::buildUI()
{

}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug() << "ddddddddddddddddddddddddddddd";
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug() << "ffffffffffffffffffffffffff";
}
