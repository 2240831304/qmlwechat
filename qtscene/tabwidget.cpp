#include "tabwidget.h"
#include <QTabWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QHBoxLayout>
#include <QIcon>
#include <QTabBar>
#include <QPalette>

Tabwidget::Tabwidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("QTabWidgetDemo");
    resize(800,600);
    initface();
}


void Tabwidget::initface()
{
    QTabWidget *tabWidget = new QTabWidget(this);
    //tabWidget->setTabShape(QTabWidget::Triangular);//设置选项卡的形状 Rounded
    tabWidget->setMovable(true);  //设置表头可以拖动换位置
    tabWidget->setTabPosition(QTabWidget::North);
    tabWidget->setIconSize(QSize(20,20));
    tabWidget->setTabsClosable(true);

    QIcon iconClose(":/image/close.png");
    QPushButton *closeBut = new QPushButton(this);
    //closeBut->setGeometry(0,0,0,0);
    closeBut->setIcon(iconClose);

    QPalette pal = closeBut->palette();              //startBtn是我已经定义好的QPushButton对象
    pal.setColor(QPalette::ButtonText, Qt::red);    //设置按钮上的字体颜色，理论上可以，实际上就是可以
    pal.setColor(QPalette::Button, Qt::green);      //设置按钮背景颜色，理论上可以，实际上不可以

    closeBut->setPalette(pal);
    closeBut->setFixedSize(15,15);
    //closeBut.setStyleSheet("background-color:green");


    //新建第一个页面的部件
    QWidget *widget = new QWidget(this);
    QLineEdit *lineEdit = new QLineEdit(widget);
    QPushButton *pushButton = new QPushButton("Test",widget);
    QVBoxLayout *vLayout = new QVBoxLayout(widget);
    vLayout->addWidget(lineEdit);
    vLayout->addWidget(pushButton);

    //向QTabWidget中添加第一个页面
    //QIcon icon1(":/image/1.png");
    //tabWidget->addTab(widget,icon1,"Tab1");
    tabWidget->addTab(widget,"Tab1");
    //((QTabBar*)(tabWidget->tabBar()))->setTabButton(tabWidget->indexOf(widget),QTabBar::RightSide,NULL);
    //((QTabBar*)(tabWidget->tabBar()))->setTabButton(tabWidget->indexOf(widget),QTabBar::RightSide,closeBut);

    //新建第二个页面的部件
    QLabel *label = new QLabel("Hello Qt",this);
    //QIcon icon2(":/image/2.png");
    //tabWidget->addTab(label,icon2,"Tab2");
    tabWidget->addTab(label,"Tab2");

    //新建第三个页面的部件
    QPushButton *pushButton3 = new QPushButton("Click Me",this);
    //QIcon icon3(":/image/3.png");
    //tabWidget->addTab(pushButton3,icon3,"Tab3");
    tabWidget->addTab(pushButton3,"Tab3");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tabWidget);

}
