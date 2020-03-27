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

    int getAppNumber();

private:
    void loadAppData();

private:
    QVector<AppInfo> dataVector;
};

#endif // DATA_H
