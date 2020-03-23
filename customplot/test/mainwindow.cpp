#include "mainwindow.h"
#include <QTime>
#include "qcustomplot.h"
#include <QVBoxLayout>
#include <QPushButton>

#define STATUS 2
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    resize(600,600);

    initCustomPlot();
    drawPic();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initCustomPlot()
{
    QPushButton *button = new QPushButton("stop",this);
    connect(button,SIGNAL(clicked()),
            this,SLOT(stopRealtimeCurve()));

    customPlot = new QCustomPlot(this);
    customPlot->resize(400,400);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(customPlot);
    layout->addWidget(button);
    setLayout(layout);

    stopBol = true;

    customPlot->resize(this->width(),this->height());
    customPlot->xAxis->setVisible(true);
    customPlot->yAxis->setVisible(true);
    // 设置顶边线和右边线显示但不显示刻度值
    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);
    customPlot->xAxis2->setTicks(false);
    customPlot->yAxis2->setTicks(false);

    // 设置拖拽、放大缩小功能
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void MainWindow::drawPic()
{

#if (STATUS == 1)
    curve();
#elif (STATUS == 2)
    setupRealtimeDataDemo();
#elif (STATUS == 3)
    dealDrawLine();
#else
    dealDrawBarChart();
#endif
}

void MainWindow::setupRealtimeDataDemo()
{
    customPlot->addGraph(); // blue line
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setName("temp");

    customPlot->addGraph(); // red line
    customPlot->graph(1)->setPen(QPen(Qt::red));
    customPlot->graph(1)->setName("hui");

    //customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
   // customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
   // customPlot->xAxis->setAutoTickStep(true);
   // customPlot->xAxis->setTickLabelPadding(2);
   // customPlot->axisRect()->setupFullAxesBox();

    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));

    QDateTime dateTime = QDateTime::currentDateTime();
    double  now = dateTime.toTime_t();//当前时间转化为秒
    customPlot->xAxis->setRange(now, now+10);//x轴范围，从当前时间起往后推1分钟
    customPlot->yAxis->setRange(0,60);
    sumData = now;

    // Interval 0 means to refresh as fast as possible
    dataTimer.start(500);
    customPlot->setNotAntialiasedElements(QCP::aeAll);
    customPlot->legend->setVisible(true);
}

void MainWindow::realtimeDataSlot()
{
#if 0
    //key的单位是秒
    double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
    qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);

    //使用随机数产生两条曲线
    double value0 = qrand() % 100;
    double value1 = qrand() % 80;

    customPlot->graph(0)->addData(key, value0);//添加数据1到曲线1
    customPlot->graph(1)->addData(key, value1);//添加数据2到曲线2

    //删除8秒之前的数据。这里的8要和下面设置横坐标宽度的8配合起来
    //才能起到想要的效果，可以调整这两个值，观察显示的效果。
    //customPlot->graph(0)->removeDataBefore(key-8);
    //customPlot->graph(1)->removeDataBefore(key-8);

     //自动设定graph(1)曲线y轴的范围，如果不设定，有可能看不到图像
    //也可以用ui->customPlot->yAxis->setRange(up,low)手动设定y轴范围
    customPlot->graph(0)->rescaleValueAxis();
    customPlot->graph(1)->rescaleValueAxis(true);

    //这里的8，是指横坐标时间宽度为8秒，如果想要横坐标显示更多的时间
    //就把8调整为比较大到值，比如要显示60秒，那就改成60。
    //这时removeDataBefore(key-8)中的8也要改成60，否则曲线显示不完整。
    customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);//设定x轴的范围
#else
    //生成时间刻度对象
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker(new QCPAxisTickerDateTime);
    customPlot->xAxis->setTicker(dateTimeTicker);
    //dateTimeTicker->setDateTimeSpec(Qt::UTC);//设施世界时间，即不加上时区的时间
    dateTimeTicker->setTickCount(10);
    dateTimeTicker->setTickStepStrategy(QCPAxisTicker::tssMeetTickCount);
    customPlot->xAxis->setSubTicks(true);

    dateTimeTicker->setDateTimeFormat("yyyy-M-d h:m");//设置x轴刻度显示格式
    customPlot->xAxis->setTickLabelRotation(90);//设置刻度标签顺时针旋转30度
    customPlot->xAxis->setLabel("时间");
    customPlot->yAxis->setLabel("温度/摄氏度");


//    customPlot->graph(0)->removeDataBefore(key-0.5);
    QDateTime dateTime = QDateTime::currentDateTime();
    qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 10000);
    double  now = dateTime.toTime_t();//当前时间转化为秒
    //customPlot->xAxis->setRange(now, 60,Qt::AlignHorizontal_Mask);//x轴范围，从当前时间起往后推1分钟
    //customPlot->xAxis->setRangeReversed(true);
    //生成数据
    double xData1 = now;
    double yData1 = qrand() % 60;
    customPlot->graph(0)->addData(xData1,yData1);

    if((now - sumData) > 10)
        customPlot->xAxis->setRange(now,10,Qt::AlignRight);

//    customPlot->xAxis->setRange(now, now+3600*24);//x轴范围，从当前时间起往后推24小时
//    customPlot->yAxis->setRange(0,60);

//    xData.push_back(now);
//    yData.push_back(qrand() % 60 );
//    customPlot->graph(0)->setData(xData,yData);
 #endif

    customPlot->replot();
}

void MainWindow::curve()
{
    //定义两个可变数组存放绘图的坐标数据
    QVector<double> savex(101),savey(101);//分别存放x和y坐标的数据,101为数据长度
    //添加数据，我们这里演示y=x^3,为了正负对称，我们x从-10到+10
    for(int i=0;i<101;i++)
    {
        savex[i] = i/5 - 10;
        savey[i] = savex[i] * savex[i] * savex[i];
    }

     //向绘图区域QCustomPlot(从widget提升来的)添加一条曲线
     customPlot->addGraph();
     //添加数据
    customPlot->graph(0)->setData(savex,savey);


    //设置坐标轴标签名称
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");

    //设置坐标轴显示范围,否则我们只能看到默认的范围
    customPlot->xAxis->setRange(-11,11);
    customPlot->yAxis->setRange(-1100,1100);

    //重绘，这里可以不用，官方例子有，执行setData函数后自动重绘
    //我认为应该用于动态显示或者是改变坐标轴范围之后的动态显示，我们以后探索
    //customPlot->replot();
}

//绘制直线
void MainWindow::dealDrawLine()
{
    customPlot->xAxis->setRange(0, 9);
    customPlot->yAxis->setRange(0, 9);
    customPlot->setBackground(QBrush(QColor(Qt::gray)));

    QPen drawPen;
    drawPen.setColor(Qt::blue);
    drawPen.setWidth(1);

    QVector<double> xLineVector, yLineVector;
    xLineVector << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    yLineVector << 4 << 1 << 2 << 4 << 5 << 6 << 7;

    QCPGraph * curGraph = customPlot->addGraph();
    curGraph->setPen(drawPen);
    curGraph->setLineStyle(QCPGraph::lsLine);
    curGraph->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
    curGraph->setData(xLineVector, yLineVector);
    customPlot->replot();
}

//绘制柱状图
void MainWindow::dealDrawBarChart()
{
    int plottableCount = customPlot->plottableCount();
    if (plottableCount != 0)
        customPlot->clearPlottables();

    customPlot->xAxis->setRange(-1, 8);
    customPlot->yAxis->setRange(-1, 12);

//    QLinearGradient gradient(0, 0, 0, 400);
//    gradient.setColorAt(0, QColor(90, 90, 90));
//    gradient.setColorAt(0.38, QColor(100, 100, 100));
//    gradient.setColorAt(1, QColor(70, 70, 70));
//    customPlot->setBackground(QBrush(gradient));

    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));//开始颜色为黑色
    gradient.setColorAt(0.38, QColor(200, 105, 105));//红色
    gradient.setColorAt(1, QColor(70, 70, 70));//黑色
    customPlot->setBackground(QBrush(gradient));//设置图表背景（用画刷设置）


    QVector<double> xBarVector, yBarVector;
    xBarVector << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    yBarVector << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;

    QCPBars *rectBar = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    rectBar->setAntialiased(false);
    rectBar->setStackingGap(1);
    rectBar->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    rectBar->setBrush(QColor(0, 168, 140));
   // rectBar->addData(12,34);
    rectBar->setData(xBarVector, yBarVector);

    customPlot->replot();
}

void MainWindow::stopRealtimeCurve()
{
    if(stopBol) {
        dataTimer.stop();
        stopBol = false;
        qDebug() << "11111111stop";
    } else {
        dataTimer.start();
        stopBol = true;
        qDebug() << "2222222start";
   }
}
