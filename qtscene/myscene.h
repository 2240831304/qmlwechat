#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include "data.h"

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyScene(QObject *parent = 0);

protected:
    void drawBackground ( QPainter * painter, const QRectF & rect );
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    void buildTest();
    void buildUI();

};

#endif // MYSCENE_H
