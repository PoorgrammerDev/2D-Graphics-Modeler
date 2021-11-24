#ifndef SQUARE_H
#define SQUARE_H

#include <QString>
#include "Shape.h"

class Square: public Shape
{
public:
    void GetSquare();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[3];
};

#endif // SQUARE_H
