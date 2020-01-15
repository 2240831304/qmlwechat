#include "calculatorserver.h"
#include <QDebug>

CalculatorServer::CalculatorServer(QObject *parent)
    : QObject(parent)
{

}


int CalculatorServer::getTestValue()
{
    return 23;
}

void CalculatorServer::testFunction()
{
    qDebug() << "CalculatorServer::testFunction()=========";
}
