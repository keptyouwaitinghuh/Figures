#include "Circle.h"

Circle::Circle(qreal h): r(h),Rectangable(2 * h,2 * h)
{
    setRect ( field );
}

void Circle::findSquare()
{
    square=3.1415926*r*r;
}

void Circle::findPerimeter()
{
    perimeter=2*3.1415926 * r;
}

