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
            case ShapeType::Line :
                // Drawing a line
                painter.setPen(shapes[index]->GetPen());
                shapes[index]->Draw(painter);
                break;
            case ShapeType::Polyline :
                // Drawing a polyline
                painter.setPen(shapes[index]->GetPen());
                shapes[index]->Draw(painter);
                break;
            case ShapeType::Ellipse :
                // Drawing an Ellipse
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->Draw(painter);
                break;
            case ShapeType::Polygon :
                // Drawing a Polygon
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->Draw(painter);
                break;
            case ShapeType::Rectangle :
                // Drawing a Rectangle
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->Draw(painter);
                break;
            case ShapeType::Text :
                // Drawing text
                // need to add the text details
                shapes[index]->Draw(painter);
                break;
            }

            ++index;
    }
}





