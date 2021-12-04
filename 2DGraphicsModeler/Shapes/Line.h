#ifndef LINE_H
#define LINE_H

#include <QString>
#include <QPainter>
#include "Shape.h"

class Line: public Shape
{
public:
    Line();
    Line(const Line& obj) = delete;
    virtual ~Line() override;

    // Added these three methods to each shape
    virtual void Draw(QPainter& aPainter) override;
    virtual void SetDimensions(int point[]) override;
    // May not actually need this
    QLine getLine();

    virtual void Serialize(std::ostream& out) override;
private:
    // USed for render area ease with dimensions, may change like discusses
    QLine line;
};

#endif // LINE_H
