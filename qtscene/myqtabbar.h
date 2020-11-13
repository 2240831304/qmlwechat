#ifndef MYQTABBAR_H
#define MYQTABBAR_H

#include <QPaintEvent>
#include <QTabBar>

class MyQTabBar : public QTabBar
{
public:
    MyQTabBar();

protected:
    void paintEvent(QPaintEvent *);

};

#endif // MYQTABBAR_H
