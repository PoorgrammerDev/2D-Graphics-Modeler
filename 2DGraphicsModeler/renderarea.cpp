#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    input.ReadShapes(shapes);
}

RenderArea::~RenderArea()
{
    // Perhaps add serializer
    // Do we need to do anything with vector here?
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    int index = 0;

    // Looing through entire vector to display
    while (index < shapes.size())
    {
   //     Used for testing QPoints with poly shapes
   //     QPoint points[4]={QPoint(10,20), QPoint(20, 30), QPoint(30, 40), QPoint(40, 50)};

            switch (shapes[index]->GetType()) {
            case 0:
                // Drawing a line
                painter.setPen(shapes[index]->GetPen());
                shapes[index]->draw(painter);
                break;
            case 1:
                // Drawing a polyline
                painter.setPen(shapes[index]->GetPen());
                shapes[index]->draw(painter);
                break;
            case 2:
                // Drawing an Ellipse
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->draw(painter);
                break;
            case 3:
                // Drawing a Polygon
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->draw(painter);
                break;
            case 4:
                // Drawing a Rectangle
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->draw(painter);
                break;
            case 5:
                // Drawing text
                // need to add the text details
                shapes[index]->draw(painter);
                break;
            }

            ++index;
    }
}





