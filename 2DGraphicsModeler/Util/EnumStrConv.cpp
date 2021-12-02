#include "EnumStrConv.h"
#include <iostream>

QString GColorEnumToStr(Qt::GlobalColor val) {
    QString str[] = {"color0", "color1", "black", "white", "darkGray", "gray", "lightGray", "red", "green", "blue", "cyan", "magenta", "yellow", "darkRed", "darkGreen", "darkBlue", "darkCyan", "darkMagenta", "darkYellow", "transparent"};

    return str[static_cast<int>(val)];
}

QString PenStyleToStr(Qt::PenStyle val) {

    switch (val) {
    case Qt::NoPen:
        return "NoPen";

    }

    QString str[] = {"NoPen", "SolidLine", "DashLine", "DotLine", "DashDotLine", "DashDotDotLine", "CustomDashLine", "MPenStyle"};

    std::cout << (int) Qt::CustomDashLine << "\n";

    return str[static_cast<int>(val)];
}
/*
Qt::GlobalColor GColorEnumFromStr(QString str) {
	
}




Qt::PenStyle PenStyleFromStr(QString str) {
	
}


QString PenCapStyleToStr(Qt::PenCapStyle val) {
    QString str[] = {};
    return str[static_cast<int>(val)];
}

Qt::PenCapStyle PenCapStyleFromStr(QString str) {
	
}


QString PenJoinStyleToStr(Qt::PenJoinStyle val) {
    QString str[] = {};
    return str[static_cast<int>(val)];
}

Qt::PenJoinStyle PenJoinStyleFromStr(QString str) {
	
}


QString BrushStyleToStr(Qt::BrushStyle val) {
    QString str[] = {};
    return str[static_cast<int>(val)];
}

Qt::BrushStyle BrushStyleFromStr(QString str) {
	
}


QString AlignFlagToStr(Qt::AlignmentFlag val) {
    QString str[] = {};
    return str[static_cast<int>(val)];
}

Qt::AlignmentFlag AlignFlagFromStr(QString str) {
	
}


QString FontStyleToStr(QFont::Style val) {
    QString str[] = {};
    return str[static_cast<int>(val)];
}

QFont::Style FontStyleFromStr(QString str) {
	
}


QString FontWeightToStr(QFont::Weight val) {
    QString str[] = {};
    return str[static_cast<int>(val)];
}

QFont::Weight FontWeightFromStr(QString str) {
	
}*/

