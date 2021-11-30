#ifndef SQUARE_H
#define SQUARE_H

#include <QString>
#include "Polygon.h"

class Square: public Polygon
{
public:
    void GetSquare();

    Square();
    ~Square();
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[3];
};

#endif // SQUARE_H
