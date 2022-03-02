#ifndef RECT_H
#define RECT_H
#include "Rectangable.h"

class Rect : public Rectangable, public QGraphicsRectItem
{
private:
    qreal h;
    qreal w;
public:
    Rect(qreal width, qreal height);

    void findSquare();
    void findPerimeter();
};

#endif // RECT_H
