#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

class Shape
{
public:
    int ChooseShape();
  //  virtual void paint();

    Shape();
    ~Shape();
private:
    int shapeId;
    QString shapeType;
    QString shapeColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    int shapeDimensions[4];
};

#endif // SHAPE_H
