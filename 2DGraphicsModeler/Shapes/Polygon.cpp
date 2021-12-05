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

Polygon::Polygon(int id, QPen pen, Qt::GlobalColor penColor, QBrush brush, Qt::GlobalColor brushColor, int dimensions[])
    : Shape(id, ShapeType::Polygon, pen, penColor, brush, brushColor) {
    Polygon::SetDimensions(dimensions);
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


void Polygon::Serialize(std::ostream& out) {
    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Polygon\n"

    << "ShapeDimensions: "
            /*<< shapeDimensions[0]*/ << ", " //FIXME: find dims
            /*<< shapeDimensions[1]*/ << ", "
            /*<< shapeDimensions[2]*/ << ", "
            /*<< shapeDimensions[3]*/ << ", "
            /*<< shapeDimensions[4]*/ << ", "
            /*<< shapeDimensions[5]*/ << ", "
            /*<< shapeDimensions[6]*/ << ", "
            /*<< shapeDimensions[7]*/ << '\n'

    << "PenColor: " << GColorToStr(penColor).toStdString() << '\n'
    << "PenWidth: " << pen.width() << '\n'
    << "PenStyle: " << PenStyleToStr(pen.style()).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(pen.capStyle()).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(pen.joinStyle()).toStdString() << '\n'
    << "BrushColor: " << GColorToStr(brushColor).toStdString() << '\n'
    << "BrushStyle: " << BrushStyleToStr(brush.style()).toStdString() << "\n\n";
}

void Polygon::Move() {
    //TODO: Unimplemented method stub
}

double Polygon::Perimeter() {
    return 0.0; //TODO: Unimplemented method stub
}

double Polygon::Area() {
    return 0.0; //TODO: Unimplemented method stub
}

/***********************
 * Setters and Getters *
 ***********************/

// Not done, need to add some sort of loop to add all of the points
void Polygon::SetDimensions(int point[])
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
