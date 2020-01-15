#ifndef CALCULATORSERVER_H
#define CALCULATORSERVER_H

#include <QObject>

class CalculatorServer : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorServer(QObject *parent = nullptr);

    Q_INVOKABLE int getTestValue();
    Q_INVOKABLE void testFunction();

signals:

public slots:
};

#endif // CALCULATORSERVER_H
