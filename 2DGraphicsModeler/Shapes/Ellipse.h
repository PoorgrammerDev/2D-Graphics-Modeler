#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QString>
#include "Polygon.h"

class Ellipse: public Polygon
{
public:
    Ellipse();
    Ellipse(const Ellipse& obj) = delete;
    virtual ~Ellipse() override;

    void GetEllipse();
    virtual void Serialize(std::ostream& out) override;
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[4];
};

#endif // ELLIPSE_H
