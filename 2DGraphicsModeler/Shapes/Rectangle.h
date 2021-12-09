#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QString>
#include "Polygon.h"

class Rectangle: public Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Rectangle();
    Rectangle(int id, ShapeType type, QPen pen, Qt::GlobalColor penColor, QBrush brush, Qt::GlobalColor brushColor, int dimensions[]);
    Rectangle(const Rectangle& obj) = delete; //delete copy constructor
    virtual ~Rectangle() override;

    /***********************************
     * Non-Setter/Getter Class Methods *
     ***********************************/
    Rectangle& operator= (const Rectangle& obj) = delete; //delete copy assignment

    virtual void Draw(QPainter& aPainter) override;
    virtual void DrawId(QPainter& aPainter) override;
    virtual void SetDimensions(int point[]) override;
    virtual void Serialize(std::ostream& out) override;

    /***********************
     * Setters and Getters *
     ***********************/
    QRect getRectangle(); // May not actually need this

private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[4];
    // Added this for ease of renderArea with holding dimensions
    QRect rectangle;
};

#endif // RECTANGLE_H
