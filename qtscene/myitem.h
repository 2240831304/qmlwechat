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

     int getItemXpos();
     int getItemYpos();

protected:
     void drawBackground ( QPainter * painter, const QRectF & rect );
     // Shift+左键：进行选择  Alt：准备缩放
     void mousePressEvent(QGraphicsSceneMouseEvent *event);
     // Alt+拖拽：进行缩放  移动
     void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
     void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);



signals:
     void doubleSig(QString );

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
