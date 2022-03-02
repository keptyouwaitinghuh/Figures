#ifndef RECTANGABLE_H
#define RECTANGABLE_H
#include "Figure.h"
#include <QGraphicsRectItem>

class Rectangable : public Figure
{
protected:
    QRectF field;
public:
    Rectangable(qreal width, qreal height);

    QRectF getField() { return field; }
};

#endif // RECTANGABLE_H
