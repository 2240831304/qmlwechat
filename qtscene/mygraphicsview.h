#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QPointF>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent = 0);


public slots:
    void updateSlot();
    void moveRangeSlot(int,int);


private:
    QPointF InitCentOnPos;
    QPointF MoveCentOnPos;
};

#endif // MYGRAPHICSVIEW_H
