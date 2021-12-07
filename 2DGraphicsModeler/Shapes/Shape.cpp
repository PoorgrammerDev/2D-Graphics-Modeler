#include "Shape.h"

/*******************************
 * Constructors and Destructor *
 *******************************/

Shape::Shape() : shapeId(0), pen(), brush() { //TODO: randomly generate new shapeID instead

}

Shape::Shape(int id, ShapeType type, QPen pen, Qt::GlobalColor penColor, QBrush brush, Qt::GlobalColor brushColor)
    : shapeId(id), shapeType(type), pen(pen), penColor(penColor), brush(brush), brushColor(brushColor) {
    //Dimensions will be handled by derived classes
}

Shape::~Shape() {}


/***********************
 * Setters and Getters *
 ***********************/

// Sets pen attributes from input
void Shape::SetPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join)
{
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(style);
    pen.setCapStyle(cap);
    pen.setJoinStyle(join);
}

// Sets brush attributes from input
void Shape::SetBrush(Qt::GlobalColor color, Qt::BrushStyle style)
{
    brush.setColor(color);
    brush.setStyle(style);
}

// Returns the type for paint event switch in renderarea
ShapeType Shape::GetType() const
{
    return shapeType;
}

// Returns the pen so painter can be updated in renderarea
QPen Shape::GetPen() const
{
    return pen;
}

// Returns the brush so the painter can be updated in renderarea
QBrush Shape::GetBrush() const
{
    return brush;
}

bool Shape::operator== (const Shape& obj) {
    return this->shapeId == obj.shapeId;
}

bool Shape::operator< (const Shape& obj) {
    return this->shapeId < obj.shapeId;
}

bool Shape::operator<= (const Shape& obj) {
    return this->shapeId <= obj.shapeId;
}

bool Shape::operator> (const Shape& obj) {
    return this->shapeId > obj.shapeId;
}

bool Shape::operator>= (const Shape& obj) {
    return this->shapeId >= obj.shapeId;
}
