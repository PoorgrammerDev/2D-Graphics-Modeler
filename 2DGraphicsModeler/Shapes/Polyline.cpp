#include <iostream>
#include <QPainter>
#include "Polyline.h"
#include "Util/EnumStrConv.h"

/*******************************
 * Constructors and Destructor *
 *******************************/

Polyline::Polyline()
{

}

Polyline::~Polyline() {}


/***********************************
 * Non-Setter/Getter Class Methods *
 ***********************************/

void Polyline::Draw(QPainter& aPainter)
{
    // These variables are dummy fillers
    aPainter.drawPolyline(points, pointCount);
}



void Polyline::Serialize(std::ostream& out) {
    //TODO: Using filler variables until Shape is updated
    auto penColor = Qt::black;
    auto penStyle = Qt::DashDotDotLine;
    auto penCapStyle = Qt::FlatCap;
    auto penJoinStyle = Qt::MiterJoin;

    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Polyline\n"

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
    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << "\n\n";
}

void Polyline::Move() {
    //TODO: Unimplemented method stub
}

double Polyline::Perimeter() {
    return 0.0; //TODO: Unimplemented method stub
}

double Polyline::Area() {
    return 0.0; //TODO: Unimplemented method stub
}

/***********************
 * Setters and Getters *
 ***********************/

// Have not implemented these until done with polygon as they are very similar and having the same todo list for both
void Polyline::SetDimensions(int point[])
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


