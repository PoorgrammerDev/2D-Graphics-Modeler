#include "renderarea.h"

#include <QPainter>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    QWidget::setFixedHeight(500);
    QWidget::setFixedWidth(1000);
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

    // Looping through entire vector to display
    while (index < shapes.size())
    {
   //     Used for testing QPoints with poly shapes
   //   QPoint somepoints[4]={QPoint(900,90), QPoint(910, 20), QPoint(970, 40), QPoint(980, 80)};
   //   painter.drawPolygon(somepoints, 4);

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
            case ShapeType::Circle :
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
            case ShapeType::Square :
                // Drawing a Rectangle
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->Draw(painter);
                break;
            case ShapeType::Text : {
                    // Drawing text
                    // need to add the text details

                    Text* castedText = static_cast<Text*>(&(*shapes[index])); //TODO: janky solution - thomas
                    painter.setFont(castedText->GetFont());
                    castedText = nullptr;

                    shapes[index]->Draw(painter);
                    break;
                }
            }
            //painter.restore(); //What is this supposed to do? It was causing an issue (not a crash) - Thomas
            ++index;
    }
}





