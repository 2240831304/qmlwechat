
#include "drawplanpie.h"
#include <cmath>

namespace eink {

DrawPlanPieController::DrawPlanPieController()
    : totleNum(0)
{

}

DrawPlanPieController::~DrawPlanPieController()
{

}

void DrawPlanPieController::attachData(const QString &key,int num)
{
    allDataMap.insert(key,num);
    totleNum += num;
}

void DrawPlanPieController::removeData(const QString &key)
{
    totleNum = totleNum - allDataMap.value(key);
    allDataMap.remove(key);
}

void DrawPlanPieController::startDraw()
{

}

float DrawPlanPieController::calculatePercentage(int num)
{
    return num/totleNum;
}



DrawPlanPie::DrawPlanPie(QWidget *parent)
    : QWidget(parent), m_nPeopleCount(0)
{
    this->resize(600, 600);

#if 0
    this->setAutoFillBackground(true);
    setStyleSheet(QString::fromUtf8("border:3px solid red \
                    background-color:red;"));

    m_answerMap.insert("A", 3);
    m_answerMap.insert("B", 5);
   // m_answerMap.insert("C", 8);
    //m_answerMap.insert("D", 2);

    m_answerStrList = m_answerMap.keys();
    m_numList = m_answerMap.values();
    foreach (int num, m_numList) {
        m_nPeopleCount += num;
    }
#endif
}

DrawPlanPie::~DrawPlanPie()
{

}

void DrawPlanPie::paintEvent(QPaintEvent *e)
{

#if 0
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::NoBrush);
//    painter.drawImage(this->rect(),m_bg);

    QRectF rect(-240, -240,480,480);
    QList<QColor> colorList;

    //坐标原点
    painter.translate(300, 300);
    qreal startAngle = 0;

    foreach (int num, m_numList) {

        //生成随机颜色并过滤掉白色
        int colorR, colorG, colorB;
        while(1)
        {
            colorR = rand()%256;
            colorG = rand()%256;
            colorB = rand()%256;

            if(colorR == 255 && colorG == 255 && colorB == 255)
            {
                continue;
            }
            else
            {
                break;
            }
        }

        QColor color(colorR, colorG, colorB);
        colorList.append(color);

        painter.setPen(Qt::NoPen);
        painter.setBrush(QBrush(color));

        //该答案选项所占比例
        qreal percentNum = (qreal)num/(qreal)m_nPeopleCount;
        //所占比例对应的角度
        qreal arcLength = 360*percentNum;

        //画扇形
        QPainterPath path;
        path.arcTo(rect, startAngle, arcLength);

        //扇形二等分线的角度
        qreal middleAngle = startAngle + arcLength/2;
        qreal radianNum = 0;

        if(middleAngle >= 0 && middleAngle < 90)
        {
            radianNum = middleAngle*m_pi/180;
        }
        else if(middleAngle >= 90 && middleAngle < 180)
        {
            radianNum = (180 - middleAngle)*m_pi/180;
        }
        else if(middleAngle >= 180 && middleAngle < 270)
        {
            radianNum = (middleAngle - 180)*m_pi/180;
        }
        else if(middleAngle >= 270 && middleAngle < 360)
        {
            radianNum = (360 - middleAngle)*m_pi/180;
        }

        //二等分线的中点距原点的距离
        qreal textPosY = 60*sin(radianNum);
        qreal textPosX = 60*cos(radianNum);
        //根据二等分线所在的象限确定二等分线的中点坐标
        if(middleAngle >= 0 && middleAngle < 90)
        {
            textPosY = -textPosY;
        }
        else if(middleAngle >= 90 && middleAngle < 180)
        {
            textPosX = -textPosX;
            textPosY = -textPosY;
        }
        else if(middleAngle >= 180 && middleAngle < 270)
        {
            textPosX = -textPosX;
        }
        startAngle += arcLength;
        QString percentStr = QString::number(percentNum*100 + 0.5);
        percentStr = getPercentInt(percentStr) + "%";
        painter.drawPath(path);
        painter.setPen(QColor(Qt::white));
        painter.drawText(textPosX - 25, textPosY -10,
                         50, 20, Qt::AlignCenter, percentStr);
  }

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QColor(0, 0, 0));
    painter.translate(-220, -255);

    //绘制右侧的标注栏
    QFont ft;
    ft.setPixelSize(15);
    painter.setFont(ft);
    int textStart = 140;
    foreach (QString answerStr, m_answerStrList) {
        painter.drawText(350, textStart,
                         40, 16,
                         Qt::AlignRight, answerStr);
        textStart += 30;
    }

    textStart = 143;
    painter.setPen(Qt::NoPen);

    foreach (QColor color, colorList) {
        painter.setBrush(QBrush(color));
        painter.drawRect(402, textStart, 15, 15);
        textStart += 30;
    }
#endif
    QWidget::paintEvent(e);
}

QString DrawPlanPie::getPercentInt(const QString &percentStr)
{
    QString percentIntStr;
    for(int i = 0;i < percentStr.size();++i)
    {
        if(percentStr.at(i) == '.')
        {
            break;
        }
        percentIntStr += percentStr.at(i);
    }
    return percentIntStr;
}

}
