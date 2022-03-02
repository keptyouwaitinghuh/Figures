#ifndef RHOMB_H
#define RHOMB_H

#include "Rectangable.h"
#include <QGraphicsPolygonItem>

class Rhomb: public Rectangable, public QGraphicsPolygonItem
{
    qreal width;
    qreal height;

    QPolygonF core;
public:
    Rhomb(qreal width, qreal height);

    void findSquare();
    void findPerimeter();
};

#endif // RHOMB_H
