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
#include <QDebug>
#include "mytabwidget.h"

Tabwidget::Tabwidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("QTabWidgetDemo");
    resize(800,600);
    initface();
}


void Tabwidget::initface()
{
    //QTabWidget *tabWidget = new QTabWidget(this);
    //tabWidget->setTabShape(QTabWidget::Triangular);//设置选项卡的形状 Rounded

    MyTabwidget *tabWidget = new MyTabwidget(this);
    tabWidget->setMovable(true);  //设置表头可以拖动换位置
    tabWidget->setTabPosition(QTabWidget::North);
    //tabWidget->setTabPosition(QTabWidget::South);
    tabWidget->setIconSize(QSize(20,20));
    tabWidget->setTabsClosable(true);
    connect(tabWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(tabCloseRequestedSlot(int)));


    QString tabBarStyle = "QTabWidget{padding:0px;margin:0px;border:0px;}\
                          QTabBar::tab {margin-right:0px;margin-bottom:1px; min-width:50px;color: black;\
                            border-top-left-radius: 5px;border-top-right-radius: 5px;padding:5px;\
                            border-top: 1px solid; border-left: 0px solid;border-right: 1px solid;}\
                            QTabBar::tab:first{border-left: 1px solid;}\
    QTabBar::tab:!selected {margin-top: 0px;background-color: rgb(205, 201, 201);} \
    QTabBar::tab:selected {background-color: rgb(0, 238, 0);border-bottom: 2px solid;} \
    QTabBar::tab:hover:!selected{background-color: rgb(255, 165, 0);}";

    tabWidget->setStyleSheet(tabBarStyle);


    QIcon iconClose(":/image/close.png");
    QPushButton *closeBut = new QPushButton(this);
    //closeBut->setIcon(iconClose);

    QString pushButStyle = "QPushButton{width:20px;height:20px;padding:0px;border:0px;background: transparent; border-image:url(:/image/close.png);} \
            QPushButton:hover{border-image:url(:/image/1.png);} \
            QPushButton:pressed{border-image:url(:/image/2.png);}";
    closeBut->setStyleSheet(pushButStyle);

    //QPalette pal = closeBut->palette();              //startBtn是我已经定义好的QPushButton对象
    //pal.setColor(QPalette::ButtonText, Qt::red);    //设置按钮上的字体颜色，理论上可以，实际上就是可以
    //pal.setColor(QPalette::Button, Qt::green);      //设置按钮背景颜色，理论上可以，实际上不可以

    //closeBut->setPalette(pal);
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
    tabWidget->addTab(widget,"Tab1555555555555555555555");
    //((QTabBar*)(tabWidget->tabBar()))->setTabButton(tabWidget->indexOf(widget),QTabBar::RightSide,NULL);
    ((QTabBar*)(tabWidget->tabBar()))->setTabButton(tabWidget->indexOf(widget),QTabBar::RightSide,closeBut);

    //新建第二个页面的部件
    QLabel *label = new QLabel("Hello Qt",this);
    label->setStyleSheet("background-color:green");
    QIcon icon2(":/image/2.png");
    tabWidget->addTab(label,icon2,"Tab25555555555555");
    //tabWidget->addTab(label,"Tab25555555555555");

    //新建第三个页面的部件
    QPushButton *pushButton3 = new QPushButton("Click Me",this);
    //QIcon icon3(":/image/3.png");
    //tabWidget->addTab(pushButton3,icon3,"Tab3");
    tabWidget->addTab(pushButton3,"Tab3");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tabWidget);

}

void Tabwidget::tabCloseRequestedSlot(int index)
{
    qDebug() << "EEEEEEEEEEEEEEEEEEEEEEE= " << index;
}
