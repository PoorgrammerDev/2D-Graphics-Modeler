#include <iostream>
#include <string>
#include "Rectangle.h"

using std::string;
using std::cout;
using std::cin;

void Rectangle::GetRectangle()
{
    string word;
    shapeId = 4;
    shapeType = "Rectangle";

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

    //********* set dimentions here ******************
}
