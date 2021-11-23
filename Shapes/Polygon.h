#ifndef POLYGON_H
#define POLYGON_H

#include <QString>
#include "Shape.h"

class Polygon: public Shape
{
public:
    void GetPolygon();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
    int shapeSimensions[8];
};

#endif // POLYGON_H
