#ifndef ENUMSTRCONV_H
#define ENUMSTRCONV_H

#include <QColor>
#include <QPen>
#include <QBrush>
#include <Qt>
#include <QFont>
#include <QString>

QString GColorEnumToStr(Qt::GlobalColor val);
Qt::GlobalColor GColorEnumFromStr(QString str);

QString PenStyleToStr(Qt::PenStyle val);
Qt::PenStyle PenStyleFromStr(QString str);

QString PenCapStyleToStr(Qt::PenCapStyle val);
Qt::PenCapStyle PenCapStyleFromStr(QString str);

QString PenJoinStyleToStr(Qt::PenJoinStyle val);
Qt::PenJoinStyle PenJoinStyleFromStr(QString str);

QString BrushStyleToStr(Qt::BrushStyle val);
Qt::BrushStyle BrushStyleFromStr(QString str);

QString AlignFlagToStr(Qt::AlignmentFlag val);
Qt::AlignmentFlag AlignFlagFromStr(QString str);

QString FontStyleToStr(QFont::Style val);
QFont::Style FontStyleFromStr(QString str);

QString FontWeightToStr(QFont::Weight val);
QFont::Weight FontWeightFromStr(QString str);

#endif
