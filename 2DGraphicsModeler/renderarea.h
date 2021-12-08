#ifndef RENDERAREA_H
#define RENDERAREA_H

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
    //void deleteShape(int id);

public slots:
    // The example had them to update the shape so I left this section just in case
    void deleteShape(int id);
    void addEllipse(QString penColorStr, int penWidth, QString penStyleStr, QString penCapStyleStr, QString penJoinStyleStr, QString brushColorStr, QString brushStyleStr, QString dimensionsStr);
    //TODO: add rest of add's


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    vector<std::unique_ptr<Shape>> shapes;
    InputManager input;
};


#endif // RENDERAREA_H
