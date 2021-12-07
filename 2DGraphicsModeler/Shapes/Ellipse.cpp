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

Ellipse::Ellipse(int id, ShapeType type, QPen pen, Qt::GlobalColor penColor, QBrush brush, Qt::GlobalColor brushColor, int dimensions[])
    : Shape(id, type, pen, penColor, brush, brushColor){
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

void Ellipse::DrawId(QPainter& aPainter)
{
    int coords[4] = {};
    QString id = std::to_string(shapeId).c_str();
    ellipse.getCoords(&coords[0], &coords[1], &coords[2], &coords[3]);
    aPainter.drawText(coords[0], coords[3], id);
}


void Ellipse::Serialize(std::ostream& out) {
    int coords[4] = {};
    ellipse.getCoords(&coords[0], &coords[1], &coords[2], &coords[3]);

    if (shapeType == ShapeType::Circle) {
        out << "ShapeId: " << shapeId << '\n'
        << "ShapeType: Circle\n"

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
        << "ShapeType: Ellipse\n"

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


