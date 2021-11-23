#include "mainwindow.h"
int Shape::ChooseShape()
{
    int choice;
    cout << "What shape would you like to create\n"
         << "(1 - Line, 2 - Polyline, 3 - Polygon, 4 - Rectangle)\n"
         << "(5 - Square, 6 - Ellipse, 7 - Circle, 8 - Text)\n"
         << "Please enter a number: ";
    cin >> choice;
    return choice;
}

//************************************** Line ****************************************8
void Line::GetLine()
{
    string word;
    shapeId = 1;
    shapeType = "Line";

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
//************************************ Polyline ***************************************
void Polyline::GetPolyline()
{
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

    //********* set dimentions here ******************
}
//************************************ Polygon ****************************************
void Polygon::GetPolygon()
{
    string word;
    shapeId = 3;
    shapeType = "Polygon";

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

    cout << "What FillColor do you want the shape to have: ";
    getline(cin,word);
    fillColor = QString::fromStdString(word);

    cout << "What FillStyle do you want the shape to have: ";
    getline(cin,word);
    fillStyle = QString::fromStdString(word);
    //********* set dimentions here ******************
}
//*********************************** Rectangle ****************************************
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
//************************************ Square ****************************************
void Square::GetSquare()
{
    string word;
    shapeId = 5;
    shapeType = "Square";

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

    cout << "What FillColor do you want the shape to have: ";
    getline(cin,word);
    fillColor = QString::fromStdString(word);

    cout << "What FillStyle do you want the shape to have: ";
    getline(cin,word);
    fillStyle = QString::fromStdString(word);
    //********* set dimentions here ******************
}
//************************************ Ellipse ****************************************
void Ellipse::GetEllipse()
{
    string word;
    shapeId = 6;
    shapeType = "Ellipse";

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

    cout << "What FillColor do you want the shape to have: ";
    getline(cin,word);
    fillColor = QString::fromStdString(word);

    cout << "What FillStyle do you want the shape to have: ";
    getline(cin,word);
    fillStyle = QString::fromStdString(word);
    //********* set dimentions here ******************
}
//************************************ Circle ****************************************
void Circle::GetCircle()
{
    string word;
    shapeId = 7;
    shapeType = "Circle";

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

    cout << "What FillColor do you want the shape to have: ";
    getline(cin,word);
    fillColor = QString::fromStdString(word);

    cout << "What FillStyle do you want the shape to have: ";
    getline(cin,word);
    fillStyle = QString::fromStdString(word);
    //********* set dimentions here ******************
}
//************************************* Text ****************************************
void Text::GetText()
{
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
    //********* set dimentions here ******************
}
