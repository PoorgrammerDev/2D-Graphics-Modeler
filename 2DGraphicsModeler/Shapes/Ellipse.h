#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QString>
#include "Shape.h"

class Ellipse: public Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Ellipse();
    Ellipse(const Ellipse& obj) = delete;
    virtual ~Ellipse() override;

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
    // May not actually need this but kept it in case until I am done (was used in one of my fiest ideas with renderarea
    QRect getEllipse();

private:
        // Added this for ease of holding dimensions for render area drawing though I know we discussed changing it
        QRect ellipse;
};

#endif // ELLIPSE_H
