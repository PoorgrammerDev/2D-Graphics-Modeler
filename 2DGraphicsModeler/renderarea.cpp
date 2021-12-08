#include "renderarea.h"
#include <QPainter>
#include <fstream>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    QWidget::setFixedHeight(500);
    QWidget::setFixedWidth(1000);
    input.ReadShapes(shapes);
}

RenderArea::~RenderArea()
{
//   Save(); //TODO: un-comment this
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
                shapes[index]->DrawId(painter);
                break;
            case ShapeType::Polyline :
                // Drawing a polyline
                painter.setPen(shapes[index]->GetPen());
                shapes[index]->Draw(painter);
                shapes[index]->DrawId(painter);
                break;
            case ShapeType::Ellipse :
            case ShapeType::Circle :
                // Drawing an Ellipse
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->Draw(painter);
                shapes[index]->DrawId(painter);
                break;
            case ShapeType::Polygon :
                // Drawing a Polygon
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->Draw(painter);
                shapes[index]->DrawId(painter);
                break;
            case ShapeType::Rectangle :
            case ShapeType::Square :
                // Drawing a Rectangle
                painter.setPen(shapes[index]->GetPen());
                painter.setBrush(shapes[index]->GetBrush());
                shapes[index]->Draw(painter);
                shapes[index]->DrawId(painter);
                break;
            case ShapeType::Text : {
                    // Drawing text
                    // need to add the text details

                    Text* castedText = static_cast<Text*>(&(*shapes[index])); //TODO: janky solution - thomas
                    painter.setFont(castedText->GetFont());
                    castedText = nullptr;

                    shapes[index]->Draw(painter);
                    shapes[index]->DrawId(painter);
                    break;
                }
            }

            ++index;
    }
}

void RenderArea::Save() {
    std::ofstream file;

    //For some reason when I run this on my Mac, it needs a different path to get to the same place - Thomas
    //So I added some pre-processor directives that (hopefully) detect this
#if __APPLE__ && TARGET_OS_MAC
    file.open("../../../../2DGraphicsModeler/shapes.txt");
#else
    file.open("..\\2DGraphicsModeler\\shapes.txt");
#endif

    if (file.fail()) {
        std::cerr << "Save file failed to open!\n";
        return; //TODO: replace with exception?
    }

    file << '\n';
    for (int i = 0; i < shapes.size(); ++i) {
        shapes[i]->Serialize(file);
    }

    file.close();
}

void RenderArea::addEllipse(QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString brushColorStr, QString brushStyleStr, QString dimensionsStr) {
    std::unique_ptr<Shape> ellipse;
    QPen pen;
    Qt::GlobalColor penColor;
    QBrush brush;
    Qt::GlobalColor brushColor;
    int dimensions[20] = {};

    penColor = input.CheckColor(penColorStr.toStdString());
    pen.setColor(penColor);

    pen.setWidth(input.CheckSize(penWidth, 0, 20));
    pen.setStyle(input.CheckPenStyle(penStyleStr.toStdString()));
    pen.setCapStyle(input.CheckCapStyle(penCapStyleStr.toStdString()));
    pen.setJoinStyle(input.CheckJoinStyle(penJoinStyleStr.toStdString()));

    brushColor = input.CheckColor(brushColorStr.toStdString());
    brush.setColor(brushColor);
    brush.setStyle(input.CheckBrushStyle(brushStyleStr.toStdString()));
    input.PopulateRectDimensions(dimensionsStr.toStdString(), dimensions, ShapeType::Ellipse);

    ellipse = std::make_unique<Ellipse>(0, ShapeType::Ellipse, pen, penColor, brush, brushColor, dimensions);
    //TODO: Shape ID

    shapes.push_back(std::move(ellipse));
    update();
}

void RenderArea::deleteShape(int id)
{
    bool found=false;
    int index = 0;
    while(!found && index < shapes.size())
    {
        if (shapes[index]->GetId() == id)
        {
            found = true;
            shapes.erase(shapes.begin() + index ); // might be a mistake
            update();
        }
        index++;
    }
}




