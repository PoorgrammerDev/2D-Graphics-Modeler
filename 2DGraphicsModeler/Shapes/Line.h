#ifndef LINE_H
#define LINE_H

#include <QString>
#include "Shape.h"

class Line: public Shape
{
public:
    Line();
    Line(const Line& obj) = delete;
    virtual ~Line() override;

    void GetLine();
    virtual void Serialize(std::ostream& out) override;
};

#endif // LINE_H
