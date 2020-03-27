#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QGraphicsItem>

class MyItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
     MyItem();
     void setPixmap(const QString &pixPath);
     void setName(const QString &name);
     void paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
     QRectF boundingRect() const;
     void setpos(int,int);
     void setSize(int ,int );
     void setFocusStatus(bool);

protected:

private:
     QString picPath;
     QString pixName;
     int xpos;
     int ypos;
     int width;
     int height;
     bool isFocus;

};

#endif // MYITEM_H
