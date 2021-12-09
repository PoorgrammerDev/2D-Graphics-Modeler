#include <string>
#include "Line.h"
#include "Util/EnumStrConv.h"

/*******************************
 * Constructors and Destructor *
 *******************************/

Line::Line() : Shape()
{

}

Line::Line(int id, QPen pen, Qt::GlobalColor penColor, int dimensions[])
    : Shape(id, ShapeType::Line, pen, penColor, QBrush(), Qt::GlobalColor()) {
    Line::SetDimensions(dimensions, 4);
}

Line::~Line() {}


/***********************************
 * Non-Setter/Getter Class Methods *
 ***********************************/

void Line::Draw(QPainter& aPainter)
{
    aPainter.drawLine(line);
}

void Line::DrawId(QPainter& aPainter)
{
    QString id = std::to_string(shapeId).c_str();
    aPainter.setPen(QPen());
    aPainter.drawText(line.p2(), id);
}


void Line::Serialize(std::ostream& out) {
    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Line\n"

    << "ShapeDimensions: "
        << line.x1() << ", "
        << line.y1() << ", "
        << line.x2() << ", "
        << line.y2() << '\n'

    << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
    << "PenWidth: " << pen.width() << '\n'
    << "PenStyle: " << PenStyleToStr(pen.style()).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(pen.capStyle()).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(pen.joinStyle()).toStdString() << '\n';
}

/***********************
 * Setters and Getters *
 ***********************/

// Setting line dimensions from an array loaded in input for rendering
void Line::SetDimensions(int point[], const int SIZE)
{
    if (SIZE >= 4) line.setLine(point[0], point[1], point[2], point[3]);
}

// May not actually need
QLine Line::getLine()
{
    return line;
}

