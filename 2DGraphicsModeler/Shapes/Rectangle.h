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

    // Added these three methods to each shape
    virtual void draw(QPainter& aPainter) override;
    virtual void setDimensions(int point[]) override;
    // May not actrually need this
    QRect getRectangle();

    void GetRectangle();
    virtual void Serialize(std::ostream& out) override;
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[4];
    // Added this for ease of renderArea with holding dimensions
    QRect rectangle;
};

#endif // RECTANGLE_H
