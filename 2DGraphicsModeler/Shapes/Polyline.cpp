#include <iostream>
#include "Polyline.h"
#include "Util/EnumStrConv.h"

using std::string;
using std::cout;
using std::cin;

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
    << "PenWidth: " << penWidth << '\n'
    << "PenStyle: " << PenStyleToStr(penStyle).toStdString() << '\n'
    << "PenCapStyle: " << PenCapStyleToStr(penCapStyle).toStdString() << '\n'
    << "PenJoinStyle: " << PenJoinStyleToStr(penJoinStyle).toStdString() << "\n\n";
}
