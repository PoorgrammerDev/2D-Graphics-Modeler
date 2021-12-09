#ifndef POLYLINE_H
#define POLYLINE_H

#include <QString>
#include "Shape.h"

class Polyline: public Shape
{
public:
    /*******************************
     * Constructors and Destructor *
     *******************************/
    Polyline();
    Polyline(int id, QPen pen, Qt::GlobalColor penColor, int dimensions[], const int DIM_SIZE);
    Polyline(const Polyline& obj) = delete; //delete copy constructor
    virtual ~Polyline() override;

    /***********************************
     * Non-Setter/Getter Class Methods *
     ***********************************/
    Polyline& operator= (const Polyline& obj) = delete; //delete copy assignment

    // Added these three methods to each shape
    virtual void Draw(QPainter& aPainter) override;
    virtual void DrawId(QPainter& aPainter) override;
    virtual void SetDimensions(int point[], const int SIZE) override;
    virtual void Serialize(std::ostream& out) override;

    /***********************
     * Setters and Getters *
     ***********************/
    QPoint getPoints(); // May not actually need

private:
    QPoint points[10]; // Like polygon this may have more with adding QPoints for rendering
    int pointCount;
};

#endif // POLYLINE_H
