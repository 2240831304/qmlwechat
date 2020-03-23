#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "drawsolidpie.h"
#include "drawplanpie.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    resize(600,600);

#if 0
    eink::DrawSolidPie *pie = new eink::DrawSolidPie(this);
    pie->resize(300,300);
    pie->show();
#endif

# if 1
    eink::DrawPlanPieController *drwa = new eink::DrawPlanPieController();
    drwa->attachData("test1",12);
    drwa->setColor("test1",Qt::red);

    drwa->attachData("test2",5);
    drwa->setColor("test2",Qt::green);

    drwa->attachData("test3",6);
    drwa->setColor("test3",Qt::black);

    eink::DrawPlanPie *planpie = new eink::DrawPlanPie(this);
    planpie->setDataPercent(drwa->getPercentage());
    planpie->setDataColor(drwa->getColor());
    planpie->drawSector();
    planpie->show();

#endif


}

MainWindow::~MainWindow()
{

}
