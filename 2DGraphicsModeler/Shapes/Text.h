#ifndef TEXT_H
#define TEXT_H

#include <QString>
#include "Shape.h"

class Text: public Shape
{
public:
    void GetText();

    QString textString;
    QString textAli;
    int textPointSize;
    QString fontFamily;
    QString fontStyle;
    QString fontWeight;
};

#endif // TEXT_H
