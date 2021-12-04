#ifndef TEXT_H
#define TEXT_H

#include <QString>
#include "Shape.h"

class Text: public Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Text();
    Text(const Text& obj) = delete;
    virtual ~Text() override;

    /***********************************
     * Non-Setter/Getter Class Methods *
     ***********************************/
    virtual void Draw(QPainter& aPainter) override;
    virtual void SetDimensions(int point[]) override;
    virtual void Serialize(std::ostream& out) override;

    virtual void Move() override;
    virtual double Perimeter() override;
    virtual double Area() override;

    // Reading more on text with the enums and datatypes to assign to
    // Will likely add a QRect to store the dimensions as this is used in the painter.drawText() call


    /***********************
     * Setters and Getters *
     ***********************/
    void GetText();

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
