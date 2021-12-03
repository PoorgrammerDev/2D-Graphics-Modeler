#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QString>
#include "Polygon.h"

class Ellipse: public Polygon
{
public:
    Ellipse();
    Ellipse(const Ellipse& obj) = delete;
    virtual ~Ellipse() override;

    // Added these three methods for renderArea/input
    virtual void draw(QPainter& aPainter) override;
    virtual void setDimensions(int point[]) override;
    // May not actually need this but kept it in case until I am done (was used in one of my fiest ideas with renderarea
    QRect getEllipse();

    virtual void Serialize(std::ostream& out) override;
private:
        QString fillColor; // Don't think this will be needed
        QString fillStyle; // Don't think this will be needed
        int shapeDimensions[4]; // Don't think this is needed since already in base class
        // Added this for ease of holding dimensions for render area drawing though I know we discussed changing it
        QRect ellipse;
};

#endif // ELLIPSE_H
