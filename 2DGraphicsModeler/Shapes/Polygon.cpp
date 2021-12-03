#include <iostream>
#include <string>
#include "Polygon.h"
#include "Util/EnumStrConv.h"

using std::string;
using std::cout;
using std::cin;


void Polygon::GetPolygon()
{

}

Polygon::Polygon()
{

}

Polygon::~Polygon()
{

}

void Polygon::Serialize(std::ostream& out) {
    //TODO: Using filler variables until class is updated
    auto penColor = Qt::black;
    auto penStyle = Qt::DashDotDotLine;
    auto penCapStyle = Qt::FlatCap;
    auto penJoinStyle = Qt::MiterJoin;
    auto brushColor = Qt::black;
    auto brushStyle = Qt::NoBrush;

    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Polygon\n"

    << "ShapeDimensions: "
            << shapeDimensions[0] << ", "
            << shapeDimensions[1] << ", "
            << shapeDimensions[2] << ", "
            << shapeDimensions[3] << ", "
            << shapeDimensions[4] << ", "
            << shapeDimensions[5] << ", "
            << shapeDimensions[6] << ", "
            << shapeDimensions[7] << '\n'

    << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
    << "PenWidth: " << penWidth << '\n'
    << "PenStyle: " << PenStyleToStr(penStyle).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << '\n'
    << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
    << "BrushStyle: " << BrushStyleToStr(brushStyle).toStdString() << "\n\n";
}
