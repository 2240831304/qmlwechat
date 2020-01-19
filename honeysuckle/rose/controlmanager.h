#ifndef CONTROLMANAGER_H
#define CONTROLMANAGER_H

#include <QObject>

class controlmanager : public QObject
{
    Q_OBJECT
public:
    explicit controlmanager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CONTROLMANAGER_H