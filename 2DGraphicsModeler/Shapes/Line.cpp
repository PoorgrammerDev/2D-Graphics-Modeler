#include <string>
#include "Line.h"
#include "Util/EnumStrConv.h"

/*******************************
 * Constructors and Destructor *
 *******************************/

Line::Line() : Shape()
{

}

Line::Line(int id, QPen pen, int dimensions[])
    : Shape(id, ShapeType::Line, pen, QBrush()) {
    Line::SetDimensions(dimensions);
}

Line::~Line() {}


/***********************************
 * Non-Setter/Getter Class Methods *
 ***********************************/

void Line::Draw(QPainter& aPainter)
{
    aPainter.drawLine(line);
}

void Line::Serialize(std::ostream& out) {
//    //TODO: Using filler variables until class is updated
//    auto penColor = Qt::black;
//    auto penStyle = Qt::DashDotDotLine;
//    auto penCapStyle = Qt::FlatCap;
//    auto penJoinStyle = Qt::MiterJoin;

//    out << "ShapeId: " << shapeId << '\n'
//    << "ShapeType: Line\n"

//    << "ShapeDimensions: "
//        << shapeDimensions[0] << ", "
//        << shapeDimensions[1] << ", "
//        << shapeDimensions[2] << ", "
//        << shapeDimensions[3] << '\n'

//    << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
//    << "PenWidth: " << pen.width() << '\n'
//    << "PenStyle: " << PenStyleToStr(penStyle).toStdString() << '\n'
//    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
//    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << "\n\n";
}

void Line::Move() {
    //TODO: Unimplemented method stub
}

double Line::Perimeter() {
    return 0.0; //TODO: Unimplemented method stub
}

double Line::Area() {
    return 0.0; //TODO: Unimplemented method stub
}

/***********************
 * Setters and Getters *
 ***********************/

// Setting line dimensions from an array loaded in input for rendering
void Line::SetDimensions(int point[])
{
    line.setLine(point[0], point[1], point[2], point[3]);
}

// May not actually need
QLine Line::getLine()
{
    return line;
}

