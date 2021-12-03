#include <iostream>
#include "Shape.h"

using std::cout;
using std::cin;

int Shape::ChooseShape()
{
    return 0;
}

Shape::Shape()
{

}

Shape::~Shape()
{

}

// Used in input parser
void Shape:: setShapeId(int id)
{
    shapeId = id;
}

// Used in input parser so type can be used in renderarea
void Shape:: setShapeType(ShapeType aType)
{
    shapeType = aType;
}

// Sets pen attributes from input
void Shape:: setPen(Qt::GlobalColor val, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join)
{
    pen.setColor(val);
    pen.setWidth(width);
    pen.setStyle(style);
    pen.setCapStyle(cap);
    pen.setJoinStyle(join);
}

// Sets brush attributes from input
void Shape:: setBrush(Qt::GlobalColor val, Qt::BrushStyle style)
{
    brush.setColor(val);
    brush.setStyle(style);
}

// Will have set text methods here

// Returns the type for paint event switch in renderarea
ShapeType Shape:: GetType() const
{
    return shapeType;
}

// Returns the pen so painter can be updated in renderarea
QPen Shape:: GetPen() const
{
    return pen;
}

// Returns the brush so the painter can be updated in renderarea
QBrush Shape:: GetBrush() const
{
    return brush;
}
