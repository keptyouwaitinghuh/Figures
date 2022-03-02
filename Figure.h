#ifndef FIGURE_H
#define FIGURE_H
#include <QPointF>
#include <QVector>
#include <QGraphicsItem>
#include "mainwindow.h"

class Figure
{
protected:
    qreal square;
    qreal perimeter;
    QPointF massCenter;
    QPointF origin;
    QVector <QPointF> points;
    unsigned short numbOfPoints;
public:
    qreal getSquare() { return square; }
    qreal getPerimeter() { return perimeter; }
    QPointF getMassCenter() { return massCenter; }

    virtual void findSquare()=0;
    virtual void findPerimeter()=0;
};

#endif // FIGURE_H
