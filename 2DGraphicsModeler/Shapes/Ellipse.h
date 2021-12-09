#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QString>
#include "Shape.h"

//HIGHLIGHT: INHERITANCE
class Ellipse: public Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Ellipse();
    Ellipse(int id, ShapeType type, QPen pen, Qt::GlobalColor penColor, QBrush brush, Qt::GlobalColor brushColor, int dimensions[]);
    Ellipse(const Ellipse& obj) = delete; //delete copy constructor
    virtual ~Ellipse() override;

    /***********************************
     * Non-Setter/Getter Class Methods *
     ***********************************/
    Ellipse& operator= (const Ellipse& obj) = delete; //delete copy assignment

    virtual void Draw(QPainter& aPainter) override;
    virtual void DrawId(QPainter& aPainter) override;
    virtual void SetDimensions(int point[], const int SIZE) override;
    virtual void Serialize(std::ostream& out) override;

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
