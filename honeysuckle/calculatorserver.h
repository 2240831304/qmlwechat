#ifndef CALCULATORSERVER_H
#define CALCULATORSERVER_H

#include <QObject>
#include <QString>
#include <QVariantList>
#include <QVariantMap>

class CalculatorServer : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorServer(QObject *parent = nullptr);

    Q_INVOKABLE int getTestValue();
    Q_INVOKABLE void testFunction();
    Q_INVOKABLE QString calAdd(const QString &,const QString &);
    Q_INVOKABLE void callingFromQml(QVariantList list, QVariantMap map);
    Q_INVOKABLE void connectSignal();
    Q_INVOKABLE void createLayoutManager();


signals:
     void changeSig();

public slots:

private:
};

#endif // CALCULATORSERVER_H
