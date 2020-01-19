#ifndef CALCULATORCLIENT_H
#define CALCULATORCLIENT_H

#include <QObject>

class CalculatorClient : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorClient(QObject *parent = nullptr);

    Q_INVOKABLE void createUI();
    Q_INVOKABLE void testFunction();

signals:
    void testSig();

public slots:


private:

};

#endif // CALCULATORCLIENT_H
