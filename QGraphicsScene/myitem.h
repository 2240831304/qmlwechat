#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class myitem : public QObject,public QGraphicsPixmapItem
{
public:
    myitem();
};

#endif // MYITEM_H
