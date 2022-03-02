#include "Rect.h"

Rect::Rect(qreal width, qreal height) : Rectangable(width, height)
{
    findPerimeter();
    findSquare();

    h = height;
    w = width;

    setRect(field);
}

void Rect::findSquare()
{
    square = h * w;
}

void Rect::findPerimeter()
{
    perimeter = 2 * (h + w);
}
