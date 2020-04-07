#ifndef LISTVIEWMANAGER_H
#define LISTVIEWMANAGER_H

#include <QObject>

class listviewmanager : public QObject
{
    Q_OBJECT
public:
    explicit listviewmanager(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LISTVIEWMANAGER_H