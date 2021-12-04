#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QBrush>
#include <QPen>
#include <QWidget>
#include "Util/vector.h"
#include "Shapes/Shape.h"
#include "Parser/InputManager.h"


class RenderArea : public QWidget
{
    Q_OBJECT

public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();


public slots:
    // The example had them to update the shape so I left this section just in case


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    vector<std::unique_ptr<Shape>> shapes;
    InputManager input;
};


#endif // RENDERAREA_H
