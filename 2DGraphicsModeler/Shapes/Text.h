#ifndef TEXT_H
#define TEXT_H

#include <QString>
#include "Shape.h"

class Text: public Shape
{
public:
    Text();
    Text(const Text& obj) = delete;
    virtual ~Text() override;

    // Added these three methods to each shape
    virtual void Draw(QPainter& aPainter) override;
    virtual void SetDimensions(int point[]) override;
    // Reading more on text with the enums and datatypes to assign to
    // Will likely add a QRect to store the dimensions as this is used in the painter.drawText() call

    void GetText();
    virtual void Serialize(std::ostream& out) override;
private:
    QString textString;
    QString textAli;
    int textPointSize;
    QString fontFamily;
    QString fontStyle;
    QString fontWeight;
    int shapeDimensions[4];
    QRect textBox;
};

#endif // TEXT_H
