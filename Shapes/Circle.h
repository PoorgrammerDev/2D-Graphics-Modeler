#ifndef CIRCLE_H
#define CIRCLE_H

#include <QString>
#include "Shape.h"

class Circle: public Shape
{
public:
    void GetCircle();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[3];
};

#endif // CIRCLE_H
