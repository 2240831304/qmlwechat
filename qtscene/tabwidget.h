#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QWidget>

class Tabwidget : public QWidget
{
    Q_OBJECT
public:
    explicit Tabwidget(QWidget *parent = nullptr);


private:
    void initface();

signals:

public slots:
    void tabCloseRequestedSlot(int);
};

#endif // TABWIDGET_H
