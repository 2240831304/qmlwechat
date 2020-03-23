#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

class QCustomPlot;
class MainWindow : public QWidget
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();

private :
    void initCustomPlot();
    void drawPic();

    //绘制y = x ^ 3的曲线
    void curve();

    //设置qcustomplot画图属性，实时
    void setupRealtimeDataDemo();

    //绘制直线
    void dealDrawLine();
    //绘制柱状图
    void dealDrawBarChart();

private slots:
    //添加实时数据槽
    void realtimeDataSlot();

    //停止时时动态曲线
    void stopRealtimeCurve();


private:
    QCustomPlot *customPlot;
    QTimer dataTimer;
    bool stopBol;
    QVector<double> yData, xData;
    double sumData;
};

#endif // MAINWINDOW_H
