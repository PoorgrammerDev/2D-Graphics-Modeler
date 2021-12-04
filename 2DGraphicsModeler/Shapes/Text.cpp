#include <iostream>
#include <string>
#include <QString>
#include "Text.h"
#include "Util/EnumStrConv.h"
#include <QPainter>
/*******************************
 * Constructors and Destructor *
 *******************************/

Text::Text()
{

}

Text::~Text() {}

/***********************************
 * Non-Setter/Getter Class Methods *
 ***********************************/

// Have not added the methods for rendering and input as I am working on getting the enums and all the fields in the input

// Drawing a rectangle with the QRectangle
void Text::Draw(QPainter& aPainter)
{
    aPainter.drawText(textBox, textAlign, text);
}

void Text::Serialize(std::ostream& out) {
    //TODO: Using filler variables until class is updated
    auto textColor = Qt::black;
    auto textAli = Qt::AlignRight;
    auto fontStyle = QFont::StyleNormal;
    auto fontWeight = QFont::Bold;

    out << "ShapeId: " << shapeId << '\n'
    << "ShapeType: Text\n"
    << "ShapeDimensions: "
            << shapeDimensions[0] << ", "
            << shapeDimensions[1] << ", "
            << shapeDimensions[2] << ", "
            << shapeDimensions[3] << '\n'

    << "TextString: " << textString.toStdString() << '\n'
    << "TextColor: " << GColorToStr(textColor).toStdString() << '\n'
    << "TextAlignment: " << AlignFlagToStr(textAli).toStdString() << '\n'
    << "TextPointSize: " << textPointSize << '\n'
    << "TextFontFamily: " << fontFamily.toStdString() << '\n'
    << "TextFontStyle: " << FontStyleToStr(fontStyle).toStdString() << '\n'
    << "TextFontWeight: " << FontWeightToStr(fontWeight).toStdString() << "\n\n";
}

void Text::Move() {
    //TODO: Unimplemented method stub
}

double Text::Perimeter() {
    return 0.0; //TODO: Unimplemented method stub
}

double Text::Area() {
    return 0.0; //TODO: Unimplemented method stub
}

/***********************
 * Setters and Getters *
 ***********************/

// Setting Rectangle dimensions from input for rendering
void Text::SetDimensions(int point[])
{
    textBox.setCoords(point[0], point[1], point[2], point[3]);
}

