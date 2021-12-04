#include <string>
#include <QPainter>
#include "Rectangle.h"
#include "Util/EnumStrConv.h"
/*******************************
 * Constructors and Destructor *
 *******************************/

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle() {}

/***********************************
 * Non-Setter/Getter Class Methods *
 ***********************************/

// Drawing a rectangle with the QRectangle
void Rectangle::Draw(QPainter& aPainter)
{
    aPainter.drawRect(rectangle);
}

void Rectangle::Move() {
    //TODO: Unimplemented method stub
}

double Rectangle::Perimeter() {
    return 0.0; //TODO: Unimplemented method stub
}

double Rectangle::Area() {
    return 0.0; //TODO: Unimplemented method stub
}

// Thomas I changed line 64 from penWidth to pen.width() purely for compilation this is here in case I forgot to change it back!
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
    << "PenWidth: " << pen.width() << '\n'
    << "PenStyle: " << PenStyleToStr(penStyle).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << '\n'
    << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
    << "BrushStyle: " << BrushStyleToStr(brushStyle).toStdString() << "\n\n";
}

/***********************
 * Setters and Getters *
 ***********************/

// Setting Rectangle dimensions from input for rendering
void Rectangle::SetDimensions(int point[])
{
    rectangle.setCoords(point[0], point[1], point[2], point[3]);
}

// May not actually need this
QRect Rectangle::getRectangle()
{
    return rectangle;
}


