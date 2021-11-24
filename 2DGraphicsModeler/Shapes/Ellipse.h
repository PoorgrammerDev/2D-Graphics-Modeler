#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QString>
#include "Shape.h"

class Ellipse: public Shape
{
public:
    void GetEllipse();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
};

#endif // ELLIPSE_H
