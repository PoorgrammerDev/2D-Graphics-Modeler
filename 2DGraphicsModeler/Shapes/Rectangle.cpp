#include <iostream>
#include <string>
#include <QPainter>
#include "Rectangle.h"
#include "Util/EnumStrConv.h"

using std::string;
using std::cout;
using std::cin;

void Rectangle::GetRectangle()
{

}

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle()
{

}

// Setting Rectangle dimensions from input for rendering
void Rectangle:: setDimensions(int point[])
{
    rectangle.setCoords(point[0], point[1], point[2], point[3]);
}

// May not actually need this
QRect Rectangle:: getRectangle()
{
    return rectangle;
}

// Drawing a rectangle with the QRectangle
void Rectangle:: draw(QPainter& aPainter)
{
    aPainter.drawRect(rectangle);
}

void Rectangle::Serialize(std::ostream& out) {
    //TODO: Using filler variables until class is updated
    auto penColor = Qt::black;
    auto penStyle = Qt::DashDotDotLine;
    auto penCapStyle = Qt::FlatCap;
    auto penJoinStyle = Qt::MiterJoin;
    auto brushColor = Qt::black;
    auto brushStyle = Qt::NoBrush;

    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Rectangle\n"

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
