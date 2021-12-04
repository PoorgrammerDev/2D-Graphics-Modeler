#ifndef SHAPE_H
#define SHAPE_H

#include <QString>
#include <QPen>
#include <QBrush>
#include <QFont>

// Added this enum to make an easy switch in renderarea
enum class ShapeType {Line, Polyline, Ellipse, Circle, Polygon, Rectangle, Square, Text};

class Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Shape();
    Shape(int id, ShapeType type, QPen pen, QBrush brush);
    Shape(const Shape& obj) = delete;
    virtual ~Shape();

    /***********************************
     * Non-Setter/Getter Class Methods *
     ***********************************/

    // Each class has its own draw and setdimensions depending on the shape
    virtual void Draw(QPainter& aPainter) = 0;
    virtual void SetDimensions (int points[]) = 0;
    virtual void Serialize(std::ostream& out) = 0; //for writing to file

    //Do not remove: This is required by assignment PDF
    virtual void Move() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;

    /***********************
     * Setters and Getters *
     ***********************/

    // The following set the pen and brush values from the input and are assigned to painter in renderarea
    void SetPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);
    void SetBrush(Qt::GlobalColor color, Qt::BrushStyle style);

    ShapeType GetType() const;
    QPen GetPen() const;
    QBrush GetBrush() const;


//I changed this to protected so Serialize() of derived could access it.
//Not sure if this is right way to do it - Thomas
protected:
    int shapeId;
    ShapeType shapeType;
    QPen pen;
    QBrush brush;
};

#endif // SHAPE_H
