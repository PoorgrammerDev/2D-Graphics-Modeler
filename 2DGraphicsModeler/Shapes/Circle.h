#ifndef CIRCLE_H
#define CIRCLE_H

#include <QString>
#include "Polygon.h"

class Circle: public Polygon
{
public:
    void GetCircle();

    Circle();
    ~Circle();
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[3];
};

#endif // CIRCLE_H
