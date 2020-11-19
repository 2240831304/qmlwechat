#ifndef MYQTABBAR_H
#define MYQTABBAR_H

#include <QPaintEvent>
#include <QTabBar>
#include <QSize>

class MyQTabBar : public QTabBar
{
public:
    MyQTabBar();

    QSize tabSizeHint(int index) const{
        QSize s = QTabBar::tabSizeHint(index);
        s.transpose();
        return s;
   }


protected:
    void paintEvent(QPaintEvent *);

};

#endif // MYQTABBAR_H
