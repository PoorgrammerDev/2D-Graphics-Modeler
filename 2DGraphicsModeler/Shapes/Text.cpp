#include <iostream>
#include <string>
#include <QString>
#include "Text.h"
#include "Util/EnumStrConv.h"

using std::string;
using std::cout;
using std::cin;

void Text::GetText()
{
    /*
    string word;
    shapeId = 8;
    shapeType = "Text";

    cout << "What Color do you want the shape to be: ";
    getline(cin,word);
    shapeColor = QString::fromStdString(word);

    cout << "What TextAlignment do you want the text to have: ";
    getline(cin,word);
    textAli = QString::fromStdString(word);

    cout << "What Size do you want the text to be: ";
    cin  >> textPointSize;

    cout << "What FontFamily do you want the text to have: ";
    getline(cin,word);
    fontFamily = QString::fromStdString(word);

    cout << "What FontStyle do you want the text to have: ";
    getline(cin,word);
    fontStyle = QString::fromStdString(word);

    cout << "What FontWeight do you want the text to have: ";
    getline(cin,word);
    fontWeight = QString::fromStdString(word);

    cout << "What do you want the text to say: ";
    getline(cin,word);
    textString = QString::fromStdString(word);
    */
    //********* set dimentions here ******************
}

Text::Text()
{

}

Text::~Text()
{

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
