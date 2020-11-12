#include "tabwidget.h"
#include <QTabWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>

Tabwidget::Tabwidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("QTabWidgetDemo");
    resize(800,600);
    initface();
}


void Tabwidget::initface()
{
    QTabWidget *tabWidget = new QTabWidget(this);

    //新建第一个页面的部件
    QWidget *widget = new QWidget(this);
    QLineEdit *lineEdit = new QLineEdit(widget);
    QPushButton *pushButton = new QPushButton("Test",widget);
    QVBoxLayout *vLayout = new QVBoxLayout(widget);
    vLayout->addWidget(lineEdit);
    vLayout->addWidget(pushButton);

    //向QTabWidget中添加第一个页面
    //QIcon icon1(":/new/icon/images/1.ico");
    tabWidget->addTab(widget,"Tab1");

    //新建第二个页面的部件
    QLabel *label = new QLabel("Hello Qt",this);
    //QIcon icon2(":/new/icon/images/2.ico");
    tabWidget->addTab(label,"Tab2");

    //新建第三个页面的部件
    QPushButton *pushButton3 = new QPushButton("Click Me",this);
    //QIcon icon3(":/new/icon/images/3.ico");
    tabWidget->addTab(pushButton3,"Tab3");


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tabWidget);

}
