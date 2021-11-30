#ifndef POLYGON_H
#define POLYGON_H

#include <QString>
#include "Shape.h"

class Polygon: public Shape
{
public:
    void GetPolygon();

    Polygon();
    ~Polygon();
private:
    QString fillColor;
    QString fillStyle;
    int shapeSimensions[8];
};

#endif // POLYGON_H
