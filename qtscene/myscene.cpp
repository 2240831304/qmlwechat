
#include "myscene.h"

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

}

void MyScene::buildUI()
{

}
