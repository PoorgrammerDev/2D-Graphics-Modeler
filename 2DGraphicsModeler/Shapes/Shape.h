#ifndef SHAPE_H
#define SHAPE_H

#include <QString>
#include <QPen>
#include <QBrush>
#include <QFont>

// Added this enum to make an easy switch in renderarea
enum class ShapeType {Line, Polyline, Ellipse, Polygon, Rectangle, Text};

class Shape
{
public:
    /******************
     * CTORS AND DTOR *
     ******************/
    Shape();
    Shape(const Shape& obj) = delete;
    virtual ~Shape();

    /*********************************************
     * Methods added during renderarea - Juliette
     ********************************************/
    // Used in input parser to assign input
    void SetShapeId(int id);
    // Assigns the type of shape for later use in switch with types of shapes
    void SetShapeType(ShapeType aType);

    // The following set the pen and brush values from the input and are assigned to painter in renderarea
    void SetPen(Qt::GlobalColor color, int width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);
    void SetBrush(Qt::GlobalColor color, Qt::BrushStyle style);
    // *** Still need to update text details
    void SetFont(int pointSize, QString fontFam, QFont::Style fontStyle, QFont::Weight fontWeight);
    void SetText(QString aText);
    void SetTextColor(Qt::GlobalColor color);
    void SetTextAlign(Qt::AlignmentFlag anAlignment);

    // Each class has its own draw and setdimensions depending on the shape
    virtual void Draw(QPainter& aPainter) = 0;
    virtual void SetDimensions (int points[]) = 0;

    // The following simply return the fields for use in renderarea paintevent
    ShapeType GetType() const;
    QPen GetPen() const;
    QBrush GetBrush()const;
    QFont GetFont() const;
    QString GetText() const;
    Qt::GlobalColor GetTextColor() const;
    Qt::AlignmentFlag GetTextAlight() const;


    /******************
     * OTHER METHODS *
     ******************/
    int ChooseShape(); //Is this required? - Thomas


    virtual void Serialize(std::ostream& out) = 0; //pure virtual serialize function - for writing to file


//I changed this to protected so Serialize() of derived could access it.
//Not sure if this is right way to do it - Thomas
protected:
    int shapeId;
    ShapeType shapeType;
    QPen pen;
    QBrush brush;
    QFont font;
    QString text;
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag textAlign;

    // I ran into problems with updating the text fields and dimensions with the vector so am finalizing those two parts
    // The following was an attempted solution to set each shape to its unique dimension types
    int dimensions[10];
    QPoint points[10];
    // Will have text fields

    int shapeDimensions[4]; // I saw this after the fact so may not use this or may change what I made if it messes with serializer
};

#endif // SHAPE_H
