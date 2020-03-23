#ifndef MODELX_H
#define MODELX_H


#ifndef MODELEX_H
#define MODELEX_H

#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include <QStringList>
#include <QObject>

class modelex:public QAbstractTableModel
{
public:
    explicit modelex(QObject *parent=0);

    virtual int rowCount(const QModelIndex &parent=QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent=QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;
    //返回表头的函数
    QVariant headerData(int section,Qt::Orientation orientation,int role)const;

private:
    QVector<short> army;
    QVector<short> weaponType;

    //数值-文字映射
    QMap<short,QString> armyMap;
    QMap<short,QString> weaponTypeMap;

    QStringList weapon;
    QStringList header;

    //完成表格数据的初始化填充
    void populateModel();
};

#endif // MODELEX_H

#endif // MODELX_H
