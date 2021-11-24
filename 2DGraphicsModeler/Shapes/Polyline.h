#ifndef POLYLINE_H
#define POLYLINE_H

#include <QString>
#include "Shape.h"

class Polyline: public Shape
{
public:
    void GetPolyline();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    int shapeDimensions[8];
};

#endif // POLYLINE_H
