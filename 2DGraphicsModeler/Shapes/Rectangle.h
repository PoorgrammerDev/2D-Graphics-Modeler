#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QString>
#include "Shape.h"

class Rectangle: public Shape
{
public:
    void GetRectangle();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
};

#endif // RECTANGLE_H
