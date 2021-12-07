#include "dialog.h"
#include "ui_dialog.h"
#include "Util/EnumStrConv.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Dialog::AddFieldValues();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_shSelLine_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Line);
}

void Dialog::on_shSelText_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Text);
}

void Dialog::on_shSelRect_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Rectangle);
}

void Dialog::on_shSelPolygon_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Polygon);
}

void Dialog::on_shSelEllipse_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Ellipse);
}

void Dialog::on_shSelPolyline_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Polyline);
}

void Dialog::AddFieldValues() {
    Qt::PenStyle penStyles[] = {Qt::NoPen, Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine, Qt::DashDotDotLine, Qt::CustomDashLine, Qt::MPenStyle};
    Qt::PenCapStyle penCapStyles[] = {Qt::FlatCap, Qt::SquareCap, Qt::RoundCap, Qt::MPenCapStyle};
    Qt::PenJoinStyle penJoinStyles[] = {Qt::MiterJoin, Qt::BevelJoin, Qt::RoundJoin, Qt::SvgMiterJoin, Qt::MPenJoinStyle};
    Qt::GlobalColor colors[] = {Qt::color0, Qt::color1, Qt::black, Qt::white, Qt::darkGray, Qt::gray, Qt::lightGray, Qt::red, Qt::green, Qt::blue, Qt::cyan, Qt::magenta, Qt::yellow, Qt::darkRed, Qt::darkGreen, Qt::darkBlue, Qt::darkCyan, Qt::darkMagenta, Qt::darkYellow, Qt::transparent};

    //Pen Style
    for (Qt::PenStyle penStyle : penStyles) {
        ui->l_penStyleBox->addItem(PenStyleToStr(penStyle));
        ui->r_penStyleBox->addItem(PenStyleToStr(penStyle));
        ui->pg_penStyleBox->addItem(PenStyleToStr(penStyle));
        ui->e_penStyleBox->addItem(PenStyleToStr(penStyle));
        ui->pl_penStyleBox->addItem(PenStyleToStr(penStyle));
    }

    //Pen Cap Style
    for (Qt::PenCapStyle penCapStyle : penCapStyles) {
        ui->l_penCapBox->addItem(PenCapStyleToStr(penCapStyle));
        ui->r_penCapBox->addItem(PenCapStyleToStr(penCapStyle));
        ui->pg_penCapBox->addItem(PenCapStyleToStr(penCapStyle));
        ui->e_penCapBox->addItem(PenCapStyleToStr(penCapStyle));
        ui->pl_penCapBox->addItem(PenCapStyleToStr(penCapStyle));
    }

    //Pen Join Style
    for (Qt::PenJoinStyle penJoinStyle : penJoinStyles) {
        ui->l_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
        ui->t_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
        ui->r_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
        ui->pg_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
        ui->e_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
        ui->pl_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
    }

    for (Qt::GlobalColor color : colors) {
        ui->pg_fillColorBox->addItem(GColorToStr(color));
    }

    ui->t_fontFamilyBox->addItem(""); //TODO: What fonts?

    ui->t_fontStyleBox->addItem(FontStyleToStr(QFont::StyleItalic));
    ui->t_fontStyleBox->addItem(FontStyleToStr(QFont::StyleNormal));
    ui->t_fontStyleBox->addItem(FontStyleToStr(QFont::StyleOblique));

    ui->pg_fillStyleBox->addItem(""); //TODO: What is this? - Thomas
}
