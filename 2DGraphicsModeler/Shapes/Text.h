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
};

#endif // TEXT_H
