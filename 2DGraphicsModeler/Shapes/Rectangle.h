#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QString>
#include "Polygon.h"

class Rectangle: public Polygon
{
public:
    Rectangle();
    Rectangle(const Rectangle& obj) = delete;
    virtual ~Rectangle() override;

    void GetRectangle();
    virtual void Serialize(std::ostream& out) override;
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[4];
};

#endif // RECTANGLE_H
