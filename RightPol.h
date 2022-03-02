#ifndef RIGHTPOL_H
#define RIGHTPOL_H

#include "Polygon.h"

class RightPol:public Polygon
{
public:
    RightPol(unsigned short n);

    void findSquare();
    void findPerimeter();
};

#endif // RIGHTPOL_H
