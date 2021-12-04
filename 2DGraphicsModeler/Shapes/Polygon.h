#ifndef POLYGON_H
#define POLYGON_H

#include <QString>
#include "Shape.h"

class Polygon: public Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Polygon();
    Polygon(int id, QPen pen, QBrush brush, int dimensions[]);
    Polygon(const Polygon& obj) = delete;
    virtual ~Polygon() override;

    /***********************************
     * Non-Setter/Getter Class Methods *
     ***********************************/
    // Added these three methods to each shape
    virtual void Draw(QPainter& aPainter) override;
    virtual void SetDimensions(int point[]) override;
    virtual void Serialize(std::ostream& out) override;

    virtual void Move() override;
    virtual double Perimeter() override;
    virtual double Area() override;

    /***********************
     * Setters and Getters *
     ***********************/
    QPoint getPoints(); // May not actually need

private:
    QString fillColor;
    QString fillStyle;
    QPoint points[10]; // May add QPoints as the getPoints and setPoints may be used for this, figuring out with setting the dimensions and drawing
    int pointCount;
};

#endif // POLYGON_H
