#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QVector>

struct AppInfo
{
    QString picPath;
    QString appName;
};

class data
{
public:
    data();
    ~data();

    int getAppNumber();
    const AppInfo &getData(int );
    void loadAppData();

private:
    void loadData();

private:
    QVector<AppInfo> dataVector;
};

#endif // DATA_H
