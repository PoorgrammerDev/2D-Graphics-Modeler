#ifndef POLYGON_H
#define POLYGON_H

#include <QString>
#include "Shape.h"

class Polygon: public Shape
{
public:
    Polygon();
    Polygon(const Polygon& obj) = delete;
    virtual ~Polygon() override;

    // Added these three methods to each shape
    virtual void Draw(QPainter& aPainter) override;
    virtual void SetDimensions(int point[]) override;
    // May not actually need
    QPoint getPoints();


    void GetPolygon();
    virtual void Serialize(std::ostream& out) override;
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[8];
    // May add QPoints as the getPoints and setPoints may be used for this, figuring out with setting the dimensions and drawing
    QPoint points[10];
    int pointCount;
};

#endif // POLYGON_H
