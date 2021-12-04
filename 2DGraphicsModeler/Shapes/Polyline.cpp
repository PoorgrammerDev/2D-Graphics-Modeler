#include <iostream>
#include <QPainter>
#include "Polyline.h"
#include "Util/EnumStrConv.h"

using std::string;
using std::cout;
using std::cin;

Polyline::Polyline() {}

void Polyline::GetPolyline()
{
    /*
    string word;
    shapeId = 2;
    shapeType = "Polyline";

    cout << "What Color do you want the shape to be: ";
    getline(cin,word);
    shapeColor = QString::fromStdString(word);

    cout << "What Size do you want the Pen to be: ";
    cin  >> penWidth;

    cout << "What PenStyle do you want the shape to have: ";
    getline(cin,word);
    penStyle = QString::fromStdString(word);

    cout << "What PenCapStlye do you want the shape to have: ";
    getline(cin,word);
    penCapStyle = QString::fromStdString(word);

    cout << "What PenJoinStyle do you want the shape to be: ";
    getline(cin,word);
    penJoinStlye = QString::fromStdString(word);
    */

    //********* set dimentions here ******************
}

// Have not implemented these until done with polygon as they are very similar and having the same todo list for both
void Polyline:: SetDimensions(int point[])
{
    int index = 0;
    pointCount = 0;
    while(index < 20 && point[index] != 0)
    {
        points[0].setX(point[index]);
        points[0].setY(point[index+1]);
        ++pointCount;
        ++index;
        ++index;

    }
}


void Polyline:: Draw(QPainter& aPainter)
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
