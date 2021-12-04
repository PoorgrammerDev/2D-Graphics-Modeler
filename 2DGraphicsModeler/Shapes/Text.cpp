#include <iostream>
#include <string>
#include <QString>
#include "Text.h"
#include "Util/EnumStrConv.h"
#include <QPainter>
/*******************************
 * Constructors and Destructor *
 *******************************/

Text::Text() : Shape()
{

}

Text::Text(int id, TextData textData, int dimensions[])
    : Shape(id, ShapeType::Text, QPen(), QBrush()) {
    Text::SetDimensions(dimensions);

    QFont font = textData.font;
    SetFont(font.pointSize(), font.family(), font.style(), font.weight());

    SetText(textData.text);
    SetTextColor(textData.textColor);
    SetTextAlign(textData.textAlign);
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
//    //TODO: Using filler variables until class is updated
//    auto textColor = Qt::black;
//    auto textAli = Qt::AlignRight;
//    auto fontStyle = QFont::StyleNormal;
//    auto fontWeight = QFont::Bold;

//    out << "ShapeId: " << shapeId << '\n'
//    << "ShapeType: Text\n"
//    << "ShapeDimensions: "
//            << shapeDimensions[0] << ", "
//            << shapeDimensions[1] << ", "
//            << shapeDimensions[2] << ", "
//            << shapeDimensions[3] << '\n'

//    << "TextString: " << textString.toStdString() << '\n'
//    << "TextColor: " << GColorToStr(textColor).toStdString() << '\n'
//    << "TextAlignment: " << AlignFlagToStr(textAli).toStdString() << '\n'
//    << "TextPointSize: " << textPointSize << '\n'
//    << "TextFontFamily: " << fontFamily.toStdString() << '\n'
//    << "TextFontStyle: " << FontStyleToStr(fontStyle).toStdString() << '\n'
//    << "TextFontWeight: " << FontWeightToStr(fontWeight).toStdString() << "\n\n";
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


// Will have set text methods here
void Text::SetFont(int pointSize, QString fontFam, QFont::Style fontStyle, QFont::Weight fontWeight)
{
    font.setPointSize(pointSize);
    font.setFamily(fontFam);
    font.setStyle(fontStyle);
    font.setWeight(fontWeight);
}

void Text::SetText(QString aText)
{
    text = aText;
}

void Text::SetTextColor(Qt::GlobalColor color)
{
    textColor = color;
}


void Text::SetTextAlign(Qt::AlignmentFlag anAlignment)
{
    textAlign = anAlignment;
}

QFont Text::GetFont() const
{
    return font;
}

QString Text::GetText() const
{
    return text;
}

Qt::GlobalColor Text::GetTextColor() const
{
    return textColor;
}

Qt::AlignmentFlag Text::GetTextAlign() const
{
    return textAlign;
}
