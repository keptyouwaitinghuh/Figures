#include "RightPol.h"

RightPol::RightPol(unsigned short n): Polygon(n)
{
    for(short i=0;i<n;++i) core<<points[i];
    setPolygon(core);
    findSquare();
    findPerimeter();
}

void RightPol:: findSquare()
{
    square=r*r*numbOfPoints*tan(3.1415926/numbOfPoints);
}

void RightPol::findPerimeter()
{
    perimeter=numbOfPoints * r * sqrt(2 * (1 - cos(2*3.1415926/numbOfPoints)));
}
