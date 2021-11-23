#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

class Shape
{
public:
    int ChooseShape();

    int shapeId;
    QString shapeType;
    int shapeDimensions[4];
    QString shapeColor;
};

#endif // SHAPE_H
