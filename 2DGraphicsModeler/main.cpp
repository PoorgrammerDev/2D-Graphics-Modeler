#include "loginapp.h"
#include "renderarea.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RenderArea render;
    render.show();

    LoginApp w;
    w.show();
    return a.exec();
}
