#include "loginapp.h"


#include <iostream>
#include "Util/EnumStrConv.h"
#include <QPen>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::cout << PenStyleToStr(Qt::MPenStyle).toStdString() << "\n";

    LoginApp w;
    w.show();
    return a.exec();
}
