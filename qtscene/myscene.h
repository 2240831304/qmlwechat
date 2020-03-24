#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyScene(QObject *parent = 0);

private:
    void buildTest();
    void buildUI();

};

#endif // MYSCENE_H
