#include "Star.h"

Star::Star(unsigned short n): Polygon(n)
{
    int d=(numbOfPoints-1)/2;
    for(int i=0;i<n;++i)
    {
        QPointF h;
        QLineF l1=QLineF(points[i], points[(i+d)%n]);
        l1.intersect(QLineF(points[(i+1)%n], points[(i+n-d+1)%n]),&h);
        core<<points[i]<<h;
    }
    setPolygon(core);

}


void Star::findSquare()
{
    square=r*r*numbOfPoints*tan(3.1415926/numbOfPoints)*cos(2*3.1415926/numbOfPoints);
}

void Star:: findPerimeter()
{
    perimeter=2*numbOfPoints*r*tan(3.1415926/numbOfPoints);
}
