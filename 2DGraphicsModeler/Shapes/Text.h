#ifndef TEXT_H
#define TEXT_H

#include <QString>
#include "Shape.h"

struct TextData {
public:
    QString text;
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag textAlign;
    QFont font;
};

class Text: public Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Text();
    Text(int id, TextData textData, int dimensions[]);
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
    void SetFont(int pointSize, QString fontFam, QFont::Style fontStyle, QFont::Weight fontWeight);
    void SetText(QString aText);
    void SetTextColor(Qt::GlobalColor color);
    void SetTextAlign(Qt::AlignmentFlag anAlignment);

    QFont GetFont() const;
    QString GetText() const;
    Qt::GlobalColor GetTextColor() const;
    Qt::AlignmentFlag GetTextAlign() const;

private:
    QFont font;
    QString text;
    Qt::GlobalColor textColor;
    Qt::AlignmentFlag textAlign;
    QRect textBox;
};

#endif // TEXT_H
