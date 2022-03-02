#include"Polygon.h"
#include <cmath>

Polygon::Polygon(unsigned short n): r(100.0)
{
    origin=QPointF(390,290);
    massCenter=origin;

    numbOfPoints=n;
    this->setTransformOriginPoint(origin);
    for (short i=0;i<numbOfPoints;++i)
        points.append(QPointF( origin.x() + r * std::sin(2*3.1415926/n*i), origin.y() - r * std::cos(2*3.1415926/n*i)));
}


