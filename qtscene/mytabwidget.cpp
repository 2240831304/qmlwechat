#include "mytabwidget.h"
#include "myqtabbar.h"

MyTabwidget::MyTabwidget(QObject *parent)
{
    MyQTabBar * bar = new MyQTabBar();
    setTabBar(bar);
}


void MyTabwidget::paintEvent(QPaintEvent *)
{

}
