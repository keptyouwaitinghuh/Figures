#include "Square.h"

Square::Square(qreal squareSide) : Rectangable(squareSide,squareSide)
{

        side=squareSide;

        setRect(field);

}

void Square::findSquare()
{
    square=side*side;
}

void Square:: findPerimeter()
{
    perimeter=4*side;
}
