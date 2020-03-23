#ifndef DRAWPLANPIE_H
#define DRAWPLANPIE_H


#include <QWidget>
#include <QPainter>
#include <QMap>

namespace eink {

class DrawPlanPiePrivate;
class DrawPlanPie : public QWidget
{
    Q_OBJECT

public:
    DrawPlanPie(QWidget *parent = 0);
    ~DrawPlanPie();

protected:
    void paintEvent(QPaintEvent *e);

public :
    void drawSector();
    void setDataPercent(const QMap<QString, float> &);
    void setDataColor(const QMap<QString, QColor> &);

private :
    DrawPlanPiePrivate *d;
};


class DrawPlanPieController {
    public :
        DrawPlanPieController();
        ~DrawPlanPieController();

    public :
        void attachData(const QString &,int);
        void removeData(const QString &);

        void setColor(const QString &,int colorR,int colorG,int colorB);
        void setColor(const QString &,const QColor &);
        void setColor(const QString &,Qt::GlobalColor);

        QMap<QString, float> getPercentage();
        QMap<QString, QColor> getColor();


    private :
        float sigPercentage(int);
        void calculatedPercentage();

    private:
        QMap<QString, int> allDataMap;
        QMap<QString, float> percentageMap;
        QMap<QString, QColor> colorMap;

        float totleNum;
};

}

#endif // DRAWPLANPIE_H
