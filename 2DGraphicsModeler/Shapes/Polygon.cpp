#include <iostream>
#include <string>
#include "Polygon.h"
#include "Util/EnumStrConv.h"
#include <QPainter>

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

// Not done, need to add some sort of loop to add all of the points
void Polygon:: SetDimensions(int point[])
{
    int index = 0;
    int index2 = 0;
    pointCount = 0;
    while(index < 20 && point[index+1] != 0)
    {
        points[index2].setX(point[index]);
        points[index2].setY(point[index+1]);
        ++pointCount;
        ++index;
        ++index;
        ++index2;
    }
}


void Polygon:: Draw(QPainter& aPainter)
{
    // These variables are dummy fillers
    aPainter.drawPolygon(points, pointCount);
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
    << "PenWidth: " << pen.width() << '\n'
    << "PenStyle: " << PenStyleToStr(penStyle).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << '\n'
    << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
    << "BrushStyle: " << BrushStyleToStr(brushStyle).toStdString() << "\n\n";
}
