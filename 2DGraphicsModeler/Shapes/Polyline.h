#ifndef POLYLINE_H
#define POLYLINE_H

#include <QString>
#include "Shape.h"

class Polyline: public Shape
{
public:
    Polyline();
    Polyline(const Polyline& obj) = delete;
    virtual ~Polyline() override;

    // Added these three methods to each shape
    virtual void draw(QPainter& aPainter) override;
    virtual void setDimensions(int point[]) override;
    // May not actually need
    QPoint getPoints();

    void GetPolyline();
    virtual void Serialize(std::ostream& out) override;
private:
    int shapeDimensions[8];
    // Like polygon this may have more with adding QPoints for rendering
};

#endif // POLYLINE_H
