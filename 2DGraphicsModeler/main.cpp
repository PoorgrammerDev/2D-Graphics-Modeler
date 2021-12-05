#include "loginapp.h"
#include "renderarea.h"


#include <iostream>
#include "Util/EnumStrConv.h"
#include <QPen>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::cout << PenStyleToStr(Qt::MPenStyle).toStdString() << "\n";

    RenderArea render;
    render.show();


    LoginApp w;
    w.show();
    return a.exec();
}
