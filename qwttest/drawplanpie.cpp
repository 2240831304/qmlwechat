
#include "drawplanpie.h"
#include <cmath>
#include <QDebug>

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


float DrawPlanPieController::sigPercentage(int num)
{
    return num / totleNum;
}

void DrawPlanPieController::calculatedPercentage()
{
    float totlePercentage = 0;

    QList<QString> keyList = allDataMap.keys();
    int valuesNum = keyList.size() - 1;
    for(int i = 0; i < valuesNum ;i++ ){
        float percentage = sigPercentage(allDataMap.value(keyList[i]));
        percentageMap[keyList[i]] = percentage;
        totlePercentage += percentage;
    }
    percentageMap[keyList[valuesNum]] = 1 - totlePercentage;

}

void DrawPlanPieController::setColor(const QString &key,int colorR,int colorG,int colorB)
{
    QColor color(colorR,colorG,colorB);
    colorMap[key] = color;
}

void DrawPlanPieController::setColor(const QString &key,const QColor &type)
{
    colorMap[key] = type;
}

void DrawPlanPieController::setColor(const QString &key,Qt::GlobalColor type)
{
    QColor color(type);
    colorMap[key] = color;
}

QMap<QString, float> DrawPlanPieController::getPercentage()
{
    calculatedPercentage();
    return percentageMap;
}

QMap<QString, QColor> DrawPlanPieController::getColor()
{
    return colorMap;
}


class DrawPlanPiePrivate {
    public :
        DrawPlanPiePrivate() {
            startDrawBool = false;
        }

        QMap<QString, float> percentageMap;
        QMap<QString, QColor> colorMap;
        bool startDrawBool;
};

DrawPlanPie::DrawPlanPie(QWidget *parent)
    : QWidget(parent),d(new DrawPlanPiePrivate)
{
    this->resize(600, 600);

}

DrawPlanPie::~DrawPlanPie()
{
    if(d)
            delete d;
    d = NULL;
}

void DrawPlanPie::paintEvent(QPaintEvent *e)
{
    if(d->startDrawBool) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::NoBrush);


        QPoint widgetPoint = pos();
        QSize widgetSize = size();
        qDebug() << "x=" << widgetPoint.x() << "widgetSize = " << widgetSize.width();

        int centerCircleX = widgetPoint.x() + widgetSize.width() / 2;
        int centerCircleY = widgetPoint.y() + widgetSize.height() * 2 / 5;
        painter.translate(centerCircleX, centerCircleY);
        int circleRadius = (widgetSize.height() * 2 / 5 ) - 6;
        QRectF rect(-circleRadius, -circleRadius,circleRadius * 2,circleRadius * 2);

        QList<QString> keyList = d->percentageMap.keys();
        float startAngle = 0;
        for(int i = 0; i < keyList.size();i++) {
            painter.setPen(Qt::NoPen);
            painter.setBrush(QBrush(d->colorMap[keyList[i]]));
            float arcLength = 360 * d->percentageMap[keyList[i]];
            //draw pie pic
            QPainterPath path;
            path.arcTo(rect, startAngle, arcLength);
            painter.drawPath(path);
            startAngle += arcLength;
        }
    }

    QWidget::paintEvent(e);
}

void DrawPlanPie::drawSector()
{
    d->startDrawBool = true;
    update();
}

void DrawPlanPie::setDataPercent(const QMap<QString, float> &map)
{
    d->percentageMap = map;
}

void DrawPlanPie::setDataColor(const QMap<QString, QColor> &map)
{
    d->colorMap = map;
}


}
