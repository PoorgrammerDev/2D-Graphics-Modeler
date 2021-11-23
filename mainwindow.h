#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iomanip>
#include <iostream>
#include <QString>
#include <string>
#include <QCoreApplication>
#include <QMainWindow>

using std::cin;
using std::cout;
using std::getline;
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

//***********************************************Shape class****************************************

class Shape
{
public:
    int ChooseShape();

    int shapeId;
    QString shapeType;
    int shapeDimensions[4];
    QString shapeColor;
};

class Line: public Shape
{
public:
    void GetLine();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
};

class Polyline: public Shape
{
public:
    void GetPolyline();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    int shapeDimensions[8];
};

class Polygon: public Shape
{
public:
    void GetPolygon();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
    int shapeSimensions[8];
};

class Rectangle: public Shape
{
public:
    void GetRectangle();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
};

class Square: public Shape
{
public:
    void GetSquare();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[3];
};

class Ellipse: public Shape
{
public:
    void GetEllipse();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
};

class Circle: public Shape
{
public:
    void GetCircle();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[3];
};

class Text: public Shape
{
public:
    void GetText();

    QString textString;
    QString textAli;
    int textPointSize;
    QString fontFamily;
    QString fontStyle;
    QString fontWeight;
};
//**************************************************** Funtions *******************************


#endif // MAINWINDOW_H
