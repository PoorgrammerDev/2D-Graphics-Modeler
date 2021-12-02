#ifndef SHAPE_H
#define SHAPE_H

#include <QString>

class Shape
{
public:
    /******************
     * CTORS AND DTOR *
     ******************/
    Shape();
    Shape(const Shape& obj) = delete;
    virtual ~Shape();


    /******************
     * OTHER METHODS *
     ******************/
    int ChooseShape(); //Is this required? - Thomas
    virtual void Draw() = 0;
    virtual void Move() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;




    virtual void Serialize(std::ostream& out) = 0; //pure virtual serialize function - for writing to file


//I changed this to protected so Serialize() of derived could access it.
//Not sure if this is right way to do it - Thomas
protected:
    int shapeId;
    QString shapeType;
    QString shapeColor;
    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStyle;
    int shapeDimensions[4];
};

#endif // SHAPE_H
