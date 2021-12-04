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
    Rectangle(const Rectangle& obj) = delete;
    virtual ~Rectangle() override;

    /***********************************
     * Non-Setter/Getter Class Methods *
     ***********************************/
    virtual void Draw(QPainter& aPainter) override;
    virtual void SetDimensions(int point[]) override;
    virtual void Serialize(std::ostream& out) override;

    virtual void Move() override;
    virtual double Perimeter() override;
    virtual double Area() override;

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
