#include <iostream>
#include <string>
#include "Line.h"
#include "Util/EnumStrConv.h"

using std::string;
using std::cout;
using std::cin;



Line::Line()
{
    line.setLine(10, 10, 20, 20);
    shapeType = ShapeType(0);
}

Line::~Line()
{

}

// Setting line dimensions from an array loaded in input for rendering
void Line:: SetDimensions(int point[])
{
    line.setLine(point[0], point[1], point[2], point[3]);
}

// May not actually need
QLine Line:: getLine()
{
    return line;
}

// calling drawLine to draw the line
void Line:: Draw(QPainter& aPainter)
{
    aPainter.drawLine(line);
}

void Line::Serialize(std::ostream& out) {
    //TODO: Using filler variables until class is updated
    auto penColor = Qt::black;
    auto penStyle = Qt::DashDotDotLine;
    auto penCapStyle = Qt::FlatCap;
    auto penJoinStyle = Qt::MiterJoin;

    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Line\n"

    << "ShapeDimensions: "
        << shapeDimensions[0] << ", "
        << shapeDimensions[1] << ", "
        << shapeDimensions[2] << ", "
        << shapeDimensions[3] << '\n'

    << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
    << "PenWidth: " << pen.width() << '\n'
    << "PenStyle: " << PenStyleToStr(penStyle).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << "\n\n";
}
