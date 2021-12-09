#include <string>
#include <QPainter>
#include "Polygon.h"
#include "Util/EnumStrConv.h"

/*******************************
 * Constructors and Destructor *
 *******************************/

Polygon::Polygon() : Shape()
{

}

Polygon::Polygon(int id, QPen pen, Qt::GlobalColor penColor, QBrush brush, Qt::GlobalColor brushColor, int dimensions[], const int DIM_SIZE)
    : Shape(id, ShapeType::Polygon, pen, penColor, brush, brushColor) {
    Polygon::SetDimensions(dimensions, DIM_SIZE);
}

Polygon::~Polygon() {}


/***********************************
 * Non-Setter/Getter Class Methods *
 ***********************************/

void Polygon::Draw(QPainter& aPainter)
{
    // These variables are dummy fillers
    aPainter.drawPolygon(points, pointCount);
}

void Polygon::DrawId(QPainter& aPainter)
{
    QString id = std::to_string(shapeId).c_str();
    aPainter.setPen(QPen());
    aPainter.drawText(points[pointCount-1], id);
}

void Polygon::Serialize(std::ostream& out) {
    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Polygon\n"

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
    << "PenJoinStyle: " << PenJoinStyleToStr(pen.joinStyle()).toStdString() << '\n'
    << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
    << "BrushStyle: " << BrushStyleToStr(brush.style()).toStdString() << '\n';
}

/***********************
 * Setters and Getters *
 ***********************/

// Not done, need to add some sort of loop to add all of the points
void Polygon::SetDimensions(int point[], const int SIZE)
{
    int index = 0;
    int index2 = 0;
    pointCount = 0;
    while(index < SIZE)
    {
        points[index2].setX(point[index]);
        points[index2].setY(point[index+1]);
        ++pointCount;
        ++index;
        ++index;
        ++index2;
    }
}
