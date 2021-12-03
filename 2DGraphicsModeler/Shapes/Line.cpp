#include <iostream>
#include <string>
#include "Line.h"
#include "Util/EnumStrConv.h"

using std::string;
using std::cout;
using std::cin;

void Line::GetLine()
{

}

Line::Line()
{

}

Line::~Line()
{

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
    << "PenWidth: " << penWidth << '\n'
    << "PenStyle: " << PenStyleToStr(penStyle).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << "\n\n";
}
