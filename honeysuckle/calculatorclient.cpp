#include "calculatorclient.h"
#include <QDebug>
#include <QQuickView>
#include <QQmlContext>
#include "calculatorserver.h"


CalculatorClient::CalculatorClient(QObject *parent)
    : QObject(parent)
{

}

void CalculatorClient::testFunction()
{
    qDebug() << "CalculatorClient::testFunction()===========";
}

void CalculatorClient::createUI()
{
    QQuickView *view = new QQuickView;
    CalculatorServer *server = new CalculatorServer(this);
    view->rootContext()->setContextProperty("CalculatorServerObject",server);
    view->setSource(QUrl("qrc:/calculatorqml/surface.qml"));
    view->show();
}
