#ifndef LINE_H
#define LINE_H

#include <QString>
#include <QPainter>
#include "Shape.h"

class Line: public Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Line();
    Line(int id, QPen pen, Qt::GlobalColor penColor, int dimensions[]);
    Line(const Line& obj) = delete;
    virtual ~Line() override;

    /***********************************
     * Non-Setter/Getter Class Methods *
     ***********************************/
    virtual void Draw(QPainter& aPainter) override;
    virtual void SetDimensions(int point[]) override;
    virtual void Serialize(std::ostream& out) override;

    virtual void Move() override;
    virtual double Perimeter() override;
    virtual double Area() override;

    /***********************
     * Setters and Getters *
     ***********************/
    // May not actually need this
    QLine getLine();


private:
    // USed for render area ease with dimensions, may change like discussed
    QLine line;
};

#endif // LINE_H
