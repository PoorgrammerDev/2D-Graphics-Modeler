#include <string>
#include <QPainter>
#include "Rectangle.h"
#include "Util/EnumStrConv.h"
/*******************************
 * Constructors and Destructor *
 *******************************/

Rectangle::Rectangle() : Shape()
{

}

Rectangle::Rectangle(int id, ShapeType type, QPen pen, Qt::GlobalColor penColor, QBrush brush, Qt::GlobalColor brushColor, int dimensions[])
    : Shape(id, type, pen, penColor, brush, brushColor) {
    Rectangle::SetDimensions(dimensions);
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

void Rectangle::DrawId(QPainter& aPainter)
{
    int coords[4] = {};
    QString id = std::to_string(shapeId).c_str();
    rectangle.getCoords(&coords[0], &coords[1], &coords[2], &coords[3]);
    aPainter.drawText(coords[0], coords[3], id);
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
    int coords[4] = {};
    rectangle.getCoords(&coords[0], &coords[1], &coords[2], &coords[3]);

    if (shapeType == ShapeType::Square) {
        out << "ShapeId: " << shapeId << '\n'
        << "ShapeType: Square\n"

        << "ShapeDimensions: "
            << coords[0] << ", "
            << coords[1] << ", "
            << coords[2] << '\n'

        << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
        << "PenWidth: " << pen.width() << '\n'
        << "PenStyle: " << PenStyleToStr(pen.style()).toStdString() << '\n'
        << "PenCapStyle: " << PenCapStyleToStr(pen.capStyle()).toStdString() << '\n'
        << "PenJoinStyle: " << PenJoinStyleToStr(pen.joinStyle()).toStdString() << '\n'
        << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
        << "BrushStyle: " << BrushStyleToStr(brush.style()).toStdString() << "\n\n";
    }
    else {
        out << "ShapeId: " << shapeId << '\n'
        << "ShapeType: Rectangle\n"

        << "ShapeDimensions: "
            << coords[0] << ", "
            << coords[1] << ", "
            << coords[2] << ", "
            << coords[3] << '\n'

        << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
        << "PenWidth: " << pen.width() << '\n'
        << "PenStyle: " << PenStyleToStr(pen.style()).toStdString() << '\n'
        << "PenCapStyle: " << PenCapStyleToStr(pen.capStyle()).toStdString() << '\n'
        << "PenJoinStyle: " << PenJoinStyleToStr(pen.joinStyle()).toStdString() << '\n'
        << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
        << "BrushStyle: " << BrushStyleToStr(brush.style()).toStdString() << "\n\n";
    }
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


