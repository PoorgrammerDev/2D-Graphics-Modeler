#ifndef TEXT_H
#define TEXT_H

#include <QString>
#include "Shape.h"

class Text: public Shape
{
public:
    void GetText();

    Text();
    ~Text();
private:
    QString textString;
    QString textAli;
    int textPointSize;
    QString fontFamily;
    QString fontStyle;
    QString fontWeight;
    int shapeDimensions[4];
};

#endif // TEXT_H
