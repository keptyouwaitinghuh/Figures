#ifndef FIGURE_H
#define FIGURE_H
#include <QPointF>
#include <QVector>

class Figure
{
protected:
    double square;
    double perimeter;
    QPointF massCenter;
    QVector <QPointF> points;
public:
    Figure(int pointsNum);
    virtual double findSquare();
    virtual double findPerimeter();
    virtual QPointF findMassCenter();
    virtual void move(){};
    virtual void rotate(QPointF){};
    virtual void scale(){};
};

#endif // FIGURE_H
