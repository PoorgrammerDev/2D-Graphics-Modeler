#ifndef LINE_H
#define LINE_H

#include <QString>
#include "Shape.h"

class Polyline: public Shape
{
public:
    void GetPolyine();

    Polyline();
    ~Polyline();
private:
    int shapeSimensions[8];
};

#endif // LINE_H
