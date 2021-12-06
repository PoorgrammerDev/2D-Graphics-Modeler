#include <iostream>
#include <QPainter>
#include "Polyline.h"
#include "Util/EnumStrConv.h"

/*******************************
 * Constructors and Destructor *
 *******************************/

Polyline::Polyline() : Shape()
{

}

Polyline::Polyline(int id, QPen pen, Qt::GlobalColor penColor, int dimensions[])
    : Shape(id, ShapeType::Polyline, pen, penColor, QBrush(), Qt::GlobalColor()) {
    Polyline::SetDimensions(dimensions);
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
    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Polyline\n"

    << "ShapeDimensions: ";

    //Output points, in pairs of x0, y0, x1, y1, ... etc.
    for (int i = 0; i < pointCount; ++i) { //TODO: replace with vector and have dynamic size
        out << points[i].x() << ", " << points[i].y()
        << ((i != pointCount - 1) ? ", " : "\n");
    }

    out << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
    << "PenWidth: " << pen.width() << '\n'
    << "PenStyle: " << PenStyleToStr(pen.style()).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(pen.capStyle()).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(pen.joinStyle()).toStdString() << "\n\n";
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


