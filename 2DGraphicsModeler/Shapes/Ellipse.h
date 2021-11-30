#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QString>
#include "Polygon.h"

class Ellipse: public Polygon
{
public:
    void GetEllipse();

    Ellipse();
    ~Ellipse();
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[4];
};

#endif // ELLIPSE_H
