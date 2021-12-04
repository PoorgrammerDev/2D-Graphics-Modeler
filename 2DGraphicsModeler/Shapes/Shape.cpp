#include "Shape.h"

/*******************************
 * Constructors and Destructor *
 *******************************/

Shape::Shape()
{

}

Shape::~Shape() {}


/***********************
 * Setters and Getters *
 ***********************/

// Used in input parser
void Shape::SetShapeId(int id)
{
    shapeId = id;
}

// Used in input parser so type can be used in renderarea
void Shape::SetShapeType(ShapeType aType)
{
    shapeType = aType;
}

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

// Will have set text methods here
void Shape::SetFont(int pointSize, QString fontFam, QFont::Style fontStyle, QFont::Weight fontWeight)
{
    font.setPointSize(pointSize);
    font.setFamily(fontFam);
    font.setStyle(fontStyle);
    font.setWeight(fontWeight);
}

void Shape::SetText(QString aText)
{
    text = aText;
}

void Shape::SetTextColor(Qt::GlobalColor color)
{
    textColor = color;
}


void Shape::SetTextAlign(Qt::AlignmentFlag anAlignment)
{
    textAlign = anAlignment;
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

QFont Shape::GetFont() const
{
    return font;
}
QString Shape::GetText() const
{
    return text;
}
Qt::GlobalColor Shape::GetTextColor() const
{
    return textColor;
}
Qt::AlignmentFlag Shape::GetTextAlight() const
{
    return textAlign;
}
