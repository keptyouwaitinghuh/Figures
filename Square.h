#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangable.h"

class Square : public Rectangable, public QGraphicsRectItem
{
private:
    qreal side;
public:
    Square(qreal squareSide);

    void findSquare();
    void findPerimeter();
};

#endif // SQUARE_H
