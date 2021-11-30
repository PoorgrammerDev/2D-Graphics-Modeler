#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QString>
#include "Polygon.h"

class Rectangle: public Polygon
{
public:
    void GetRectangle();

    Rectangle();
    ~Rectangle();
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[4];
};

#endif // RECTANGLE_H
