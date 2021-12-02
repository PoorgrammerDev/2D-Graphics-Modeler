#ifndef CIRCLE_H
#define CIRCLE_H

#include <QString>
#include "Polygon.h"

/* NOTE: This class might not even need to exist in the project - Thomas
 *
 * Rationale:
 * So, I was looking previously looking through the PDF and the shapes.txt, and noticed a discrepancy.
 * The PDF didn't list Square and Circle as shapes, but the shapes.txt did.
 * What I noticed now is a new file on canvas, "shape_input_file_specs.txt" that says
 * "Square[rectangle, l=w]" and "Circle[ellipse, a=b]".
 * Maybe this means that Square and Circle shouldn't actually exist as a Shape class,
 * but instead be a special type of Rectangle and Ellipse, respectively?
 */

class Circle: public Polygon
{
public:
    void GetCircle();

    Circle();
    virtual ~Circle() override;
private:
    QString fillColor;
    QString fillStyle;
    int shapeDimensions[3];
};

#endif // CIRCLE_H
