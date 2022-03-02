#ifndef CIRCLE_H
#define CIRCLE_H
#include "Rectangable.h"
#include <QGraphicsEllipseItem>

class Circle : public Rectangable, public QGraphicsEllipseItem
{
    qreal r;
public:
    Circle(qreal r);

    void findSquare();
    void findPerimeter();
};


#endif // CIRCLE_H
