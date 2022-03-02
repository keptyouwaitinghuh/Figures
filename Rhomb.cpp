#include "Rhomb.h"

Rhomb::Rhomb (qreal w, qreal h): Rectangable(w,h), width(w), height(h)
{
    core << QPointF(field.x()+width/2,field.y()) << QPointF(field.x() + width, field.y() + height / 2) <<
            QPointF(field.x()+width/2,field.y()+height) << QPointF(field.x(),field.y() + height / 2);
    setPolygon(core);
    findSquare();
    findPerimeter();
}

void Rhomb::findSquare()
{
    square=width*height/2;
}

void Rhomb::findPerimeter()
{
    perimeter=sqrt(width*width + height*height) * 4;
}

