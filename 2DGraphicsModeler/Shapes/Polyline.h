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

    void GetPolyline();
    virtual void Serialize(std::ostream& out) override;
private:
    int shapeDimensions[8];
};

#endif // POLYLINE_H
