#ifndef STAR_H
#define STAR_H

#include "Polygon.h"

class Star: public Polygon
{
public:
    Star(unsigned short n);

    void findSquare();
    void findPerimeter();
};

#endif // STAR_H
