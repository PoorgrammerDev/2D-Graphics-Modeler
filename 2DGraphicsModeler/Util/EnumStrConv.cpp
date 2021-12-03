#include "EnumStrConv.h"
#include <iostream>

/**
* @file EnumStrConv.cpp
* @author Thomas Tran
* @brief To convert between QT Enums and Strings
* @date 12/2/2021
*/

/**********************
  I am aware this is a really messy solution,
  but it's the only way I could think of right now
  to convert between Enums and Strings so we can read
  to and from files. - Thomas
**********************/

QString GColorToStr(Qt::GlobalColor val) {
    switch (val) {
    case Qt::color0:
        return "color0";
    case Qt::color1:
        return "color1";
    case Qt::black:
        return "black";
    case Qt::white:
        return "white";
    case Qt::darkGray:
        return "darkGray";
    case Qt::gray:
        return "gray";
    case Qt::lightGray:
        return "lightGray";
    case Qt::red:
        return "red";
    case Qt::green:
        return "green";
    case Qt::blue:
        return "blue";
    case Qt::cyan:
        return "cyan";
    case Qt::magenta:
        return "magenta";
    case Qt::yellow:
        return "yellow";
    case Qt::darkRed:
        return "darkRed";
    case Qt::darkGreen:
        return "darkGreen";
    case Qt::darkBlue:
        return "darkBlue";
    case Qt::darkCyan:
        return "darkCyan";
    case Qt::darkMagenta:
        return "darkMagenta";
    case Qt::darkYellow:
        return "darkYellow";
    case Qt::transparent:
        return "transparent";
    }

    return "";
}

Qt::GlobalColor GColorFromStr(QString str) {
    if (str == "color0")
        return Qt::color0;
    else if (str == "color1")
        return Qt::color1;
    else if (str == "black")
        return Qt::black;
    else if (str == "white")
        return Qt::white;
    else if (str == "darkGray")
        return Qt::darkGray;
    else if (str == "gray")
        return Qt::gray;
    else if (str == "lightGray")
        return Qt::lightGray;
    else if (str == "red")
        return Qt::red;
    else if (str == "green")
        return Qt::green;
    else if (str == "blue")
        return Qt::blue;
    else if (str == "cyan")
        return Qt::cyan;
    else if (str == "magenta")
        return Qt::magenta;
    else if (str == "yellow")
        return Qt::yellow;
    else if (str == "darkRed")
        return Qt::darkRed;
    else if (str == "darkGreen")
        return Qt::darkGreen;
    else if (str == "darkBlue")
        return Qt::darkBlue;
    else if (str == "darkCyan")
        return Qt::darkCyan;
    else if (str == "darkMagenta")
        return Qt::darkMagenta;
    else if (str == "darkYellow")
        return Qt::darkYellow;
    else if (str == "transparent")
        return Qt::transparent;
    else throw std::invalid_argument("Invalid String to GlobalColor");
}

QString PenStyleToStr(Qt::PenStyle val) {
    switch (val) {
    case Qt::NoPen:
        return "NoPen";
    case Qt::SolidLine:
        return "SolidLine";
    case Qt::DashLine:
        return "DashLine";
    case Qt::DotLine:
        return "DotLine";
    case Qt::DashDotLine:
        return "DashDotLine";
    case Qt::DashDotDotLine:
        return "DashDotDotLine";
    case Qt::CustomDashLine:
        return "CustomDashLine";
    case Qt::MPenStyle:
        return "MPenStyle";
    }

    return "";
}

Qt::PenStyle PenStyleFromStr(QString str) {
    if (str == "NoPen")
        return Qt::NoPen;
    else if (str == "SolidLine")
        return Qt::SolidLine;
    else if (str == "DashLine")
        return Qt::DashLine;
    else if (str == "DotLine")
        return Qt::DotLine;
    else if (str == "DashDotLine")
        return Qt::DashDotLine;
    else if (str == "DashDotDotLine")
        return Qt::DashDotDotLine;
    else if (str == "CustomDashLine")
        return Qt::CustomDashLine;
    else if (str == "MPenStyle")
        return Qt::MPenStyle;
    else throw std::invalid_argument("Invalid String to PenStyle");
}

QString PenCapStyleToStr(Qt::PenCapStyle val) {
    switch (val) {
    case Qt::FlatCap:
        return "FlatCap";
    case Qt::SquareCap:
        return "SquareCap";
    case Qt::RoundCap:
        return "RoundCap";
    case Qt::MPenCapStyle:
        return "MPenCapStyle";
    }

    return "";
}

Qt::PenCapStyle PenCapStyleFromStr(QString str) {
    if (str == "FlatCap")
        return Qt::FlatCap;
    else if (str == "SquareCap")
        return Qt::SquareCap;
    else if (str == "RoundCap")
        return Qt::RoundCap;
    else if (str == "MPenCapStyle")
        return Qt::MPenCapStyle;
    else throw std::invalid_argument("Invalid String to PenCapStyle");
}

QString PenJoinStyleToStr(Qt::PenJoinStyle val) {
    switch (val) {
    case Qt::MiterJoin:
        return "MiterJoin";
    case Qt::BevelJoin:
        return "BevelJoin";
    case Qt::RoundJoin:
        return "RoundJoin";
    case Qt::SvgMiterJoin:
        return "SvgMiterJoin";
    case Qt::MPenJoinStyle:
        return "MPenJoinStyle";
    }

    return "";
}

Qt::PenJoinStyle PenJoinStyleFromStr(QString str) {
    if (str == "MiterJoin")
        return Qt::MiterJoin;
    else if (str == "BevelJoin")
        return Qt::BevelJoin;
    else if (str == "RoundJoin")
        return Qt::RoundJoin;
    else if (str == "SvgMiterJoin")
        return Qt::SvgMiterJoin;
    else if (str == "MPenJoinStyle")
        return Qt::MPenJoinStyle;
    else throw std::invalid_argument("Invalid String to PenJoinStyle");
}

QString BrushStyleToStr(Qt::BrushStyle val) {
    switch (val) {
    case Qt::NoBrush:
        return "NoBrush";
    case Qt::SolidPattern:
        return "SolidPattern";
    case Qt::Dense1Pattern:
        return "Dense1Pattern";
    case Qt::Dense2Pattern:
        return "Dense2Pattern";
    case Qt::Dense3Pattern:
        return "Dense3Pattern";
    case Qt::Dense4Pattern:
        return "Dense4Pattern";
    case Qt::Dense5Pattern:
        return "Dense5Pattern";
    case Qt::Dense6Pattern:
        return "Dense6Pattern";
    case Qt::Dense7Pattern:
        return "Dense7Pattern";
    case Qt::HorPattern:
        return "HorPattern";
    case Qt::VerPattern:
        return "VerPattern";
    case Qt::CrossPattern:
        return "CrossPattern";
    case Qt::BDiagPattern:
        return "BDiagPattern";
    case Qt::FDiagPattern:
        return "FDiagPattern";
    case Qt::DiagCrossPattern:
        return "DiagCrossPattern";
    case Qt::LinearGradientPattern:
        return "LinearGradientPattern";
    case Qt::RadialGradientPattern:
        return "RadialGradientPattern";
    case Qt::ConicalGradientPattern:
        return "ConicalGradientPattern";
    case Qt::TexturePattern:
        return "TexturePattern";
    }

    return "";
}

Qt::BrushStyle BrushStyleFromStr(QString str) {
    if (str == "NoBrush")
        return Qt::NoBrush;
    else if (str == "SolidPattern")
        return Qt::SolidPattern;
    else if (str == "Dense1Pattern")
        return Qt::Dense1Pattern;
    else if (str == "Dense2Pattern")
        return Qt::Dense2Pattern;
    else if (str == "Dense3Pattern")
        return Qt::Dense3Pattern;
    else if (str == "Dense4Pattern")
        return Qt::Dense4Pattern;
    else if (str == "Dense5Pattern")
        return Qt::Dense5Pattern;
    else if (str == "Dense6Pattern")
        return Qt::Dense6Pattern;
    else if (str == "Dense7Pattern")
        return Qt::Dense7Pattern;
    else if (str == "HorPattern")
        return Qt::HorPattern;
    else if (str == "VerPattern")
        return Qt::VerPattern;
    else if (str == "CrossPattern")
        return Qt::CrossPattern;
    else if (str == "BDiagPattern")
        return Qt::BDiagPattern;
    else if (str == "FDiagPattern")
        return Qt::FDiagPattern;
    else if (str == "DiagCrossPattern")
        return Qt::DiagCrossPattern;
    else if (str == "LinearGradientPattern")
        return Qt::LinearGradientPattern;
    else if (str == "RadialGradientPattern")
        return Qt::RadialGradientPattern;
    else if (str == "ConicalGradientPattern")
        return Qt::ConicalGradientPattern;
    else if (str == "TexturePattern")
        return Qt::TexturePattern;
    else throw std::invalid_argument("Invalid String to BrushStyle");
}

QString AlignFlagToStr(Qt::AlignmentFlag val) {
    //Leading/Trailing are omitted because they == Left/Right respectively
    switch (val) {
    case Qt::AlignLeft:
        return "AlignLeft";
    case Qt::AlignRight:
        return "AlignRight";
    case Qt::AlignHCenter:
        return "AlignHCenter";
    case Qt::AlignJustify:
        return "AlignJustify";
    case Qt::AlignAbsolute:
        return "AlignAbsolute";
    case Qt::AlignHorizontal_Mask:
        return "AlignHorizontal_Mask";
    case Qt::AlignTop:
        return "AlignTop";
    case Qt::AlignBottom:
        return "AlignBottom";
    case Qt::AlignVCenter:
        return "AlignVCenter";
    case Qt::AlignBaseline:
        return "AlignBaseline";
    case Qt::AlignVertical_Mask:
        return "AlignVertical_Mask";
    case Qt::AlignCenter:
        return "AlignCenter";
    }

    return "";
}

Qt::AlignmentFlag AlignFlagFromStr(QString str) {
    if (str == "AlignLeft")
        return Qt::AlignLeft;
    else if (str == "AlignLeading")
        return Qt::AlignLeading;
    else if (str == "AlignRight")
        return Qt::AlignRight;
    else if (str == "AlignTrailing")
        return Qt::AlignTrailing;
    else if (str == "AlignHCenter")
        return Qt::AlignHCenter;
    else if (str == "AlignJustify")
        return Qt::AlignJustify;
    else if (str == "AlignAbsolute")
        return Qt::AlignAbsolute;
    else if (str == "AlignHorizontal_Mask")
        return Qt::AlignHorizontal_Mask;
    else if (str == "AlignTop")
        return Qt::AlignTop;
    else if (str == "AlignBottom")
        return Qt::AlignBottom;
    else if (str == "AlignVCenter")
        return Qt::AlignVCenter;
    else if (str == "AlignBaseline")
        return Qt::AlignBaseline;
    else if (str == "AlignVertical_Mask")
        return Qt::AlignVertical_Mask;
    else if (str == "AlignCenter")
        return Qt::AlignCenter;

    else throw std::invalid_argument("Invalid String to AlignmentFlag");
}

QString FontStyleToStr(QFont::Style val) {
    switch (val) {
    case QFont::StyleNormal:
        return "StyleNormal";
    case QFont::StyleItalic:
        return "StyleItalic";
    case QFont::StyleOblique:
        return "StyleOblique";
    }

    return "";
}

QFont::Style FontStyleFromStr(QString str) {
    if (str == "StyleNormal")
        return QFont::StyleNormal;
    else if (str == "StyleItalic")
        return QFont::StyleItalic;
    else if (str == "StyleOblique")
        return QFont::StyleOblique;

    else throw std::invalid_argument("Invalid String to FontStyle");
}

QString FontWeightToStr(QFont::Weight val) {
    switch (val) {
    case QFont::Thin:
        return "Thin";
    case QFont::ExtraLight:
        return "ExtraLight";
    case QFont::Light:
        return "Light";
    case QFont::Normal:
        return "Normal";
    case QFont::Medium:
        return "Medium";
    case QFont::DemiBold:
        return "DemiBold";
    case QFont::Bold:
        return "Bold";
    case QFont::ExtraBold:
        return "ExtraBold";
    case QFont::Black:
        return "Black";
    }

    return "";
}

QFont::Weight FontWeightFromStr(QString str) {
    if (str == "Thin")
        return QFont::Thin;
    else if (str == "ExtraLight")
        return QFont::ExtraLight;
    else if (str == "Light")
        return QFont::Light;
    else if (str == "Normal")
        return QFont::Normal;
    else if (str == "Medium")
        return QFont::Medium;
    else if (str == "DemiBold")
        return QFont::DemiBold;
    else if (str == "Bold")
        return QFont::Bold;
    else if (str == "ExtraBold")
        return QFont::ExtraBold;
    else if (str == "Black")
        return QFont::Black;

    else throw std::invalid_argument("Invalid String to FontWeight");
}

