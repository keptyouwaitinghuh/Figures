#include "Rectangable.h"

Rectangable::Rectangable(qreal width, qreal height)
{
    origin = QPointF(390 - width / 2, 290 - height / 2);
    field = QRectF(origin,QSizeF(width, height));
    massCenter = field.center();
}
