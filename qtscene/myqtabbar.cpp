#include "myqtabbar.h"
#include <QStylePainter>
#include <QStyleOptionTab>
//#include <


MyQTabBar::MyQTabBar()
{

}


void MyQTabBar::paintEvent(QPaintEvent *)
{
    QStylePainter painter(this);
    QStyleOptionTab opt;

    for(int i = 0;i < count();i++)
    {
        initStyleOption(&opt,i);
        //画tabbar的每个控件的图形框
        painter.drawControl(QStyle::CE_TabBarTabShape, opt);
        painter.save();

        QSize s = opt.rect.size();
        //s.transpose();
        QRect r(QPoint(), s);
        r.moveCenter(opt.rect.center());
        opt.rect = r;

        QPoint c = tabRect(i).center();
        painter.translate(c);
        //painter.rotate(90);
        painter.translate(-c);
        //画文字，图标
        painter.drawControl(QStyle::CE_TabBarTabLabel,opt);
        painter.restore();
   }

}
