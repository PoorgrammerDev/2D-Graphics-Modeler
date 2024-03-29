#include "renderarea.h"
#include <QPainter>
#include <fstream>
#include <QMessageBox>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    QWidget::setFixedHeight(500);
    QWidget::setFixedWidth(1000);

    //HIGHLIGHT: EXCEPTION HANDLING
    try {
        input.ReadShapes(shapes);
    }
    catch (std::runtime_error& error) {
        QMessageBox::critical(this, "File Error", error.what());
    }

    //Adds every Shape ID (shapes from input file) to the set
    for (int i = 0; i < shapes.size(); ++i) {
        ids.insert(shapes[i]->GetId());
    }
}

RenderArea::~RenderArea()
{
    //HIGHLIGHT: SAVING ALL CHANGES BETWEEN EXECUTIONS
    Save();
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
#elif __linux__
    file.open("../2DGraphicsModeler/shapes.txt");
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
        if (i != (shapes.size() - 1)) file << '\n';
    }

    file.close();
}

void RenderArea::addEllipse(bool isCircle, QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString brushColorStr, QString brushStyleStr, QString dimensionsStr) {
    std::unique_ptr<Shape> ellipse;
    QPen pen;
    Qt::GlobalColor penColor;
    QBrush brush;
    Qt::GlobalColor brushColor;
    ShapeType type;
    int dimensions[20] = {};

    pen = input.GetPenInfo(penColor, penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr);
    brush = input.GetBrushInfo(brushColor, brushColorStr, brushStyleStr);
    type = (isCircle ? ShapeType::Circle : ShapeType::Ellipse);
    input.PopulateRectDimensions(dimensionsStr.toStdString(), dimensions, type);

    ellipse = std::make_unique<Ellipse>(NextID(), type, pen, penColor, brush, brushColor, dimensions);
    shapes.push_back(std::move(ellipse));
    update();
}

void RenderArea::addLine(QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString dimensionsStr) {
    std::unique_ptr<Shape> line;
    QPen pen;
    Qt::GlobalColor penColor;
    int dimensions[20] = {};

    pen = input.GetPenInfo(penColor, penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr);
    input.PopulateLineDimensions(dimensionsStr.toStdString(), dimensions);

    line = std::make_unique<Line>(NextID(), pen, penColor, dimensions);
    shapes.push_back(std::move(line));
    update();
}

void RenderArea::addPolygon(QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString brushColorStr, QString brushStyleStr, QString dimensionsStr) {
    std::unique_ptr<Shape> polygon;
    QPen pen;
    Qt::GlobalColor penColor;
    QBrush brush;
    Qt::GlobalColor brushColor;
    int dimensions[20] = {};
    int polySize;

    pen = input.GetPenInfo(penColor, penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr);
    brush = input.GetBrushInfo(brushColor, brushColorStr, brushStyleStr);
    polySize = input.PopulatePolyDimensions(dimensionsStr.toStdString(), dimensions, 20);

    polygon = std::make_unique<Polygon>(NextID(), pen, penColor, brush, brushColor, dimensions, polySize);
    shapes.push_back(std::move(polygon));
    update();
}

void RenderArea::addPolyline(QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString dimensionsStr) {
    std::unique_ptr<Shape> polyline;
    QPen pen;
    Qt::GlobalColor penColor;
    int dimensions[20] = {};
    int polySize;

    pen = input.GetPenInfo(penColor, penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr);
    polySize = input.PopulatePolyDimensions(dimensionsStr.toStdString(), dimensions, 20);

    polyline = std::make_unique<Polyline>(NextID(), pen, penColor, dimensions, polySize);
    shapes.push_back(std::move(polyline));
    update();
}

void RenderArea::addRectangle(bool isSquare, QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString brushColorStr, QString brushStyleStr, QString dimensionsStr) {
    std::unique_ptr<Shape> rectangle;
    QPen pen;
    Qt::GlobalColor penColor;
    QBrush brush;
    Qt::GlobalColor brushColor;
    ShapeType type;
    int dimensions[20] = {};

    pen = input.GetPenInfo(penColor, penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr);
    brush = input.GetBrushInfo(brushColor, brushColorStr, brushStyleStr);
    type = (isSquare ? ShapeType::Square : ShapeType::Rectangle);
    input.PopulateRectDimensions(dimensionsStr.toStdString(), dimensions, type);

    rectangle = std::make_unique<Rectangle>(NextID(), type, pen, penColor, brush, brushColor, dimensions);
    shapes.push_back(std::move(rectangle));
    update();
}

void RenderArea::addText(QString textContents, QString textColorStr, QString textAlignStr, int pointSize, QString fontFamilyStr, QString fontStyleStr, QString fontWeightStr, QString dimensionsStr) {
    std::unique_ptr<Text> text;
    TextData textData = input.GetTextData(textContents, textColorStr, textAlignStr, pointSize, fontFamilyStr, fontStyleStr, fontWeightStr);
    int dimensions[20]= {};

    input.PopulateRectDimensions(dimensionsStr.toStdString(), dimensions, ShapeType::Text);

    text = std::make_unique<Text>(NextID(), textData, dimensions);
    shapes.push_back(std::move(text));
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
            ids.erase(id);
            update();
        }
        index++;
    }
}

int RenderArea::NextID() {
    int id = ((shapes.size() != 0) ? shapes[shapes.size() - 1]->GetId() : 0);

    while (ids.find(id) != ids.end()) {
        ++id;
    }

    ids.insert(id);
    return id;
}

void RenderArea::MoveShape(int id, QString newDimensions) {
    bool found = false;
    int i = 0;
    int dimensions[20] = {};
    int dimSize = 4;

    while (!found && i < shapes.size()) {
        if (shapes[i]->GetId() == id) {
            found = true;
        }
        else {
            ++i;
        }
    }

    switch (shapes[i]->GetType()) {
    case ShapeType::Line :
        input.PopulateLineDimensions(newDimensions.toStdString(), dimensions);
        break;
    case ShapeType::Polyline :
        dimSize = input.PopulatePolyDimensions(newDimensions.toStdString(), dimensions, 20);
        break;
    case ShapeType::Ellipse :
        input.PopulateRectDimensions(newDimensions.toStdString(), dimensions, ShapeType::Ellipse);
        break;
    case ShapeType::Circle :
        input.PopulateRectDimensions(newDimensions.toStdString(), dimensions, ShapeType::Circle);
        break;
    case ShapeType::Polygon :
        dimSize = input.PopulatePolyDimensions(newDimensions.toStdString(), dimensions, 20);
        break;
    case ShapeType::Rectangle :
        input.PopulateRectDimensions(newDimensions.toStdString(), dimensions, ShapeType::Rectangle);
        break;
    case ShapeType::Square :
        input.PopulateRectDimensions(newDimensions.toStdString(), dimensions, ShapeType::Square);
        break;
    case ShapeType::Text :
        input.PopulateRectDimensions(newDimensions.toStdString(), dimensions, ShapeType::Text);
        break;
    }

    shapes[i]->SetDimensions(dimensions, dimSize);
    update();
}


