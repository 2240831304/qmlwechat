#include "calculatorserver.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickView>

CalculatorServer::CalculatorServer(QObject *parent)
    : QObject(parent)
{
    QQmlApplicationEngine *engine = new QQmlApplicationEngine;
    engine->load(QUrl(QStringLiteral("qrc:/calculatorqml/surface.qml")));
    QObject *pRoot = engine->rootObjects().first();
    if(pRoot) {
        qDebug() << "CalculatorServer::CalculatorServer connectSignal() qml!!!!!";
        QObject::connect(this,SIGNAL(changeSig()),pRoot,SLOT(changeText()));
    }

}

CalculatorServer::~CalculatorServer()
{
   qDebug() << "CalculatorServer::~CalculatorServer() delete!!";
}


int CalculatorServer::getTestValue()
{
    return 23;
}

void CalculatorServer::testFunction()
{
    qDebug() << "CalculatorServer::testFunction()=========";
}

QString CalculatorServer::calAdd(const QString &str1,const QString &str2)
{
    //int num1 = atoi(str1.c_str());
    //int num2 = atoi(str2.c_str());

    int num1 = str1.toInt();
    int num2 = str2.toInt();
    int result = num1+num2;
    qDebug() << "std::string CalculatorServer::calAdd========" << result;

    return QString::number(result);
    //return std::to_string(result);
}

void CalculatorServer::callingFromQml(QVariantList list, QVariantMap map)
{
    int count = list.count();
    qDebug() << "CalculatorServer::callingFromQml count: " << list.count();
    qDebug() << "CalculatorServer::callingFromQml the array values are: ";
    for ( int i = 0; i < count; i++ ) {
        QString value = list[i].toString();
        qDebug() << "value: " << value;
    }
    qDebug() << "The object values are: ";
    qDebug() << "map.from:" << map["from"].toString();
    qDebug() << "map.to:" << map["to"].toString();
    qDebug() << "map.message:" << map["message"].toString();
}

void CalculatorServer::connectSignal()
{
    emit changeSig();
}

void CalculatorServer::createLayoutManager()
{
//    QQuickView *view = new QQuickView;
//    view->setSource(QUrl("qrc:/calculatorqml/layoutmanager.qml"));
//    view->show();
    QQmlApplicationEngine *engine = new QQmlApplicationEngine;
    engine->load(QUrl(QStringLiteral("qrc:/calculatorqml/layoutmanager.qml")));
    if (engine->rootObjects().isEmpty())
        return ;
}

void CalculatorServer::createListView()
{

}


void CalculatorServer::createAnimation()
{
    QQmlApplicationEngine *engine = new QQmlApplicationEngine;
    //engine->load(QUrl(QStringLiteral("qrc:/mainqml/SequentialAnimation.qml")));
    engine->load(QUrl(QStringLiteral("qrc:/mainqml/stateAnimation.qml")));

    if (engine->rootObjects().isEmpty())
        return ;
}

