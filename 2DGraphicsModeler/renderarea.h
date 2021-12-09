#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <unordered_set>
#include <QBrush>
#include <QPen>
#include <QWidget>
#include "Util/vector.h"
#include "Shapes/Shape.h"
#include "Shapes/Ellipse.h"
#include "Shapes/Line.h"
#include "Shapes/Polygon.h"
#include "Shapes/Polyline.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Text.h"
#include "Parser/InputManager.h"

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);
    virtual ~RenderArea();
    void Save();

    void MoveShape(int id, QString newDimensions);

public slots:
    void deleteShape(int id);
    void addEllipse(bool isCircle, QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString brushColorStr, QString brushStyleStr, QString dimensionsStr);
    void addLine(QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString dimensionsStr);
    void addPolygon(QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString brushColorStr, QString brushStyleStr, QString dimensionsStr);
    void addPolyline(QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString dimensionsStr);
    void addRectangle(bool isSquare, QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString brushColorStr, QString brushStyleStr, QString dimensionsStr);
    void addText(QString textContents, QString textColorStr, QString textAlignStr, int pointSize, QString fontFamilyStr, QString fontStyleStr, QString fontWeightStr, QString dimensionsStr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    vector<std::unique_ptr<Shape>> shapes;
    std::unordered_set<int> ids;
    InputManager input;

    int NextID();
};


#endif // RENDERAREA_H
