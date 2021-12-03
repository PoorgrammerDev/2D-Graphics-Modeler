#include <iostream>
#include <string>
#include <QString>
#include <QPainter>
#include "Ellipse.h"
#include "Util/EnumStrConv.h"

using std::string;
using std::cout;
using std::cin;



Ellipse::Ellipse()
{

}

Ellipse::~Ellipse()
{

}

// Using an array loaded in input parser to set dimensions for painter
void Ellipse:: setDimensions(int point[])
{
    ellipse.setCoords(point[0], point[1], point[2], point[3]);
}

// May not actually need this as mentioned before
QRect Ellipse:: getEllipse()
{
    return ellipse;
}

// Calling drawEllipse with painter to draw
void Ellipse:: draw(QPainter& aPainter)
{
    aPainter.drawEllipse(ellipse);
}

void Ellipse::Serialize(std::ostream& out) {
    //TODO: Using filler variables until class is updated
    auto penColor = Qt::black;
    auto penStyle = Qt::DashDotDotLine;
    auto penCapStyle = Qt::FlatCap;
    auto penJoinStyle = Qt::MiterJoin;
    auto brushColor = Qt::black;
    auto brushStyle = Qt::NoBrush;

    //TODO: add special case for circle? or keep in separate class?

    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Ellipse\n"

    << "ShapeDimensions: "
        << shapeDimensions[0] << ", "
        << shapeDimensions[1] << ", "
        << shapeDimensions[2] << ", "
        << shapeDimensions[3] << '\n'

    << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
    << "PenWidth: " << penWidth << '\n'
    << "PenStyle: " << PenStyleToStr(penStyle).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << '\n'
    << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
    << "BrushStyle: " << BrushStyleToStr(brushStyle).toStdString() << "\n\n";
}
