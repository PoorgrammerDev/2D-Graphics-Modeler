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
    virtual void draw(QPainter& aPainter) override;
    virtual void setDimensions(int point[]) override;
    // May not actually need
    QPoint getPoints();


    void GetPolygon();
    virtual void Serialize(std::ostream& out) override;
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[8];
    // May add QPoints as the getPoints and setPoints may be used for this, figuring out with setting the dimensions and drawing
};

#endif // POLYGON_H
