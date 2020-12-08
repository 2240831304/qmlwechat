#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include "data.h"
#include <QPoint>
#include <QGraphicsItem>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyScene(QObject *parent = 0);
    ~MyScene();

protected:
    void drawBackground ( QPainter * painter, const QRectF & rect );
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    void init();
    void clear();
    void buildTest();
    void buildUI();

private slots:
    void focusItemChangedSlot(QGraphicsItem *newFocusItem, QGraphicsItem *oldFocusItem, Qt::FocusReason reason);


signals:
    void updateSig();

private:
    int itemWidth;
    int itemHeight;
    int showItemNumber;

    int moveItemNum;
    data *dataObjec;

    bool isMousePress;
    QPoint pressedPos;

    int totleAppNum;
    int showFirstAppIndex;
    int showEndAppIndex;

};

#endif // MYSCENE_H
