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

    void GetPolygon();
    virtual void Serialize(std::ostream& out) override;
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[8];
};

#endif // POLYGON_H
