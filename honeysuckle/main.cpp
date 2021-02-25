#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QtQml>
#include "calculatorclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<CalculatorClient>("org.com.calculatorclient",1,1,"Calculator");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/mainqml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
