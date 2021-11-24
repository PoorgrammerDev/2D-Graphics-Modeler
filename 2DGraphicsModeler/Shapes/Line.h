#ifndef LINE_H
#define LINE_H

#include <QString>
#include "Shape.h"

class Line: public Shape
{
public:
    void GetLine();

    int penWidth;
    QString penStyle;
    QString penCapStyle;
    QString penJoinStlye;
};

#endif // LINE_H
