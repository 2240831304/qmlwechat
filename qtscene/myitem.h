#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QGraphicsItem>

class MyItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
     MyItem();
};

#endif // MYITEM_H
