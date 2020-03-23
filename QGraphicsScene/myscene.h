#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

class Myscene : public QGraphicsScene
{
    Q_OBJECT
public:
    Myscene(QObject *parent = 0);

};

#endif // MYSCENE_H
