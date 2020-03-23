#ifndef DRAWPIE_H
#define DRAWPIE_H

#include <QObject>
#include <QWidget>

namespace eink {

class DrawSolidPie : public QWidget
{
    Q_OBJECT
public:
    DrawSolidPie(QWidget *parent = 0);
    ~DrawSolidPie();


protected :
    void paintEvent(QPaintEvent *e);
};

}

#endif // PIE_H
