#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H

#include <QTabWidget>

class MyTabwidget : public QTabWidget
{

public:
    MyTabwidget(QObject *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

};

#endif // MYTABWIDGET_H
