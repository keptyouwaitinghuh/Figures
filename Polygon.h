#ifndef POLYGON_H
#define POLYGON_H

#include "Figure.h"
#include <QGraphicsPolygonItem>

class Polygon: public Figure , public QGraphicsPolygonItem
{
protected:
    QPolygonF core;
    qreal r;

public:
    Polygon(unsigned short n);
    QPointF getMassCenter();
};


#endif // POLYGON_H
