#include <string>
#include <QString>
#include <QPainter>
#include "Ellipse.h"
#include "Util/EnumStrConv.h"

/*******************************
 * Constructors and Destructor *
 *******************************/

Ellipse::Ellipse() : Shape()
{

}

Ellipse::Ellipse(int id, ShapeType type, QPen pen, QBrush brush, int dimensions[])
    : Shape(id, type, pen, brush){
    Ellipse::SetDimensions(dimensions);
}

Ellipse::~Ellipse() {}


/***********************************
 * Non-Setter/Getter Class Methods *
 ***********************************/

// Calling drawEllipse with painter to draw
void Ellipse::Draw(QPainter& aPainter)
{
    aPainter.drawEllipse(ellipse);
}


void Ellipse::Serialize(std::ostream& out) {
//    //TODO: add special case for circle

//    if (shapeType == ShapeType::Circle) {

//    }

//    else {

//    }

//    out << "ShapeId: " << shapeId << '\n'
//    << "ShapeType: Ellipse\n"

//    << "ShapeDimensions: "
//        << shapeDimensions[0] << ", "
//        << shapeDimensions[1] << ", "
//        << shapeDimensions[2] << ", "
//        << shapeDimensions[3] << '\n'

//    << "PenColor: " << GColorToStr(pen.color()).toStdString() << '\n'
//    << "PenWidth: " << pen.width() << '\n'
//    << "PenStyle: " << PenStyleToStr(pen.style()).toStdString() << '\n'
//    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
//    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << '\n'
//    << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
//    << "BrushStyle: " << BrushStyleToStr(brushStyle).toStdString() << "\n\n";
}

void Ellipse::Move() {
    //TODO: Unimplemented method stub
}

double Ellipse::Perimeter() {
    return 0.0; //TODO: Unimplemented method stub
}

double Ellipse::Area() {
    return 0.0; //TODO: Unimplemented method stub
}

/***********************
 * Setters and Getters *
 ***********************/

// Using an array loaded in input parser to set dimensions for painter
void Ellipse::SetDimensions(int point[])
{
    ellipse.setCoords(point[0], point[1], point[2], point[3]);
}

// May not actually need this as mentioned before
QRect Ellipse::getEllipse()
{
    return ellipse;
}


