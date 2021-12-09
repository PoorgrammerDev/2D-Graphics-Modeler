#include "dialog.h"
#include "ui_dialog.h"
#include "Util/EnumStrConv.h"
#include "QMessageBox"

const char selectShapeStyle[] = "color: #75b6ff; font-weight: bold;"; //CSS-like Syntax

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Dialog::AddFieldValues();
    Dialog::on_shSelLine_clicked(); //Auto-selects Line (top of list)
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_shSelLine_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Line);

    ui->shSelText->setStyleSheet("");
    ui->shSelRect->setStyleSheet("");
    ui->shSelPolygon->setStyleSheet("");
    ui->shSelPolyline->setStyleSheet("");
    ui->shSelEllipse->setStyleSheet("");
    ui->shSelLine->setStyleSheet(selectShapeStyle);
}

void Dialog::on_shSelText_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Text);

    ui->shSelLine->setStyleSheet("");
    ui->shSelRect->setStyleSheet("");
    ui->shSelPolygon->setStyleSheet("");
    ui->shSelPolyline->setStyleSheet("");
    ui->shSelEllipse->setStyleSheet("");
    ui->shSelText->setStyleSheet(selectShapeStyle);
}

void Dialog::on_shSelRect_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Rectangle);

    ui->shSelText->setStyleSheet("");
    ui->shSelLine->setStyleSheet("");
    ui->shSelPolygon->setStyleSheet("");
    ui->shSelPolyline->setStyleSheet("");
    ui->shSelEllipse->setStyleSheet("");
    ui->shSelRect->setStyleSheet(selectShapeStyle);
}

void Dialog::on_shSelPolygon_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Polygon);

    ui->shSelText->setStyleSheet("");
    ui->shSelRect->setStyleSheet("");
    ui->shSelLine->setStyleSheet("");
    ui->shSelPolyline->setStyleSheet("");
    ui->shSelEllipse->setStyleSheet("");
    ui->shSelPolygon->setStyleSheet(selectShapeStyle);
}

void Dialog::on_shSelEllipse_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Ellipse);

    ui->shSelText->setStyleSheet("");
    ui->shSelRect->setStyleSheet("");
    ui->shSelPolygon->setStyleSheet("");
    ui->shSelPolyline->setStyleSheet("");
    ui->shSelLine->setStyleSheet("");
    ui->shSelEllipse->setStyleSheet(selectShapeStyle);
}

void Dialog::on_shSelPolyline_clicked()
{
    ui->shapeBuilder->setCurrentWidget(ui->Polyline);

    ui->shSelText->setStyleSheet("");
    ui->shSelRect->setStyleSheet("");
    ui->shSelPolygon->setStyleSheet("");
    ui->shSelLine->setStyleSheet("");
    ui->shSelEllipse->setStyleSheet("");
    ui->shSelPolyline->setStyleSheet(selectShapeStyle);
}

void Dialog::AddFieldValues() {
    Qt::PenStyle penStyles[] = {Qt::NoPen, Qt::SolidLine, Qt::DashLine, Qt::DotLine, Qt::DashDotLine, Qt::DashDotDotLine, Qt::CustomDashLine, Qt::MPenStyle};
    Qt::PenCapStyle penCapStyles[] = {Qt::FlatCap, Qt::SquareCap, Qt::RoundCap, Qt::MPenCapStyle};
    Qt::PenJoinStyle penJoinStyles[] = {Qt::MiterJoin, Qt::BevelJoin, Qt::RoundJoin, Qt::SvgMiterJoin, Qt::MPenJoinStyle};
    Qt::GlobalColor colors[] = {Qt::color0, Qt::color1, Qt::black, Qt::white, Qt::darkGray, Qt::gray, Qt::lightGray, Qt::red, Qt::green, Qt::blue, Qt::cyan, Qt::magenta, Qt::yellow, Qt::darkRed, Qt::darkGreen, Qt::darkBlue, Qt::darkCyan, Qt::darkMagenta, Qt::darkYellow, Qt::transparent};
    QFont::Weight weights[] = {QFont::Thin, QFont::ExtraLight, QFont::Light, QFont::Normal, QFont::Medium, QFont::DemiBold, QFont::Bold, QFont::ExtraBold, QFont::Black};
    Qt::AlignmentFlag aligns[] = {Qt::AlignLeft, Qt::AlignLeading, Qt::AlignRight, Qt::AlignTrailing, Qt::AlignHCenter, Qt::AlignJustify, Qt::AlignAbsolute, Qt::AlignHorizontal_Mask, Qt::AlignTop, Qt::AlignBottom, Qt::AlignVCenter, Qt::AlignBaseline, Qt::AlignVertical_Mask, Qt::AlignCenter};
    Qt::BrushStyle brushes[] = {Qt::NoBrush, Qt::SolidPattern, Qt::Dense1Pattern, Qt::Dense2Pattern, Qt::Dense3Pattern, Qt::Dense4Pattern, Qt::Dense5Pattern, Qt::Dense6Pattern, Qt::Dense7Pattern, Qt::HorPattern, Qt::VerPattern, Qt::CrossPattern, Qt::BDiagPattern, Qt::FDiagPattern, Qt::DiagCrossPattern, Qt::LinearGradientPattern, Qt::RadialGradientPattern, Qt::ConicalGradientPattern, Qt::TexturePattern};

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
        ui->r_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
        ui->pg_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
        ui->e_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
        ui->pl_penJoinBox->addItem(PenJoinStyleToStr(penJoinStyle));
    }

    //Colors
    for (Qt::GlobalColor color : colors) {
        ui->l_penColorBox->addItem(GColorToStr(color));
        ui->t_textColorBox->addItem(GColorToStr(color));
        ui->r_brushColorBox->addItem(GColorToStr(color));
        ui->r_penColorBox->addItem(GColorToStr(color));
        ui->e_brushColorBox->addItem(GColorToStr(color));
        ui->e_penColorBox->addItem(GColorToStr(color));
        ui->pg_brushColorBox->addItem(GColorToStr(color));
        ui->pg_penColorBox->addItem(GColorToStr(color));
        ui->pl_penColorBox->addItem(GColorToStr(color));
    }

    //Font Weight
    for (QFont::Weight weight : weights) {
        ui->t_fontWeightBox->addItem(FontWeightToStr(weight));
    }

    //Alignment
    for (Qt::AlignmentFlag align : aligns) {
        ui->t_textAlignBox->addItem(AlignFlagToStr(align));
    }

    for (Qt::BrushStyle brush : brushes) {
        ui->e_brushStyleBox->addItem(BrushStyleToStr(brush));
        ui->pg_brushStyleBox->addItem(BrushStyleToStr(brush));
        ui->r_brushStyleBox->addItem(BrushStyleToStr(brush));
    }

    ui->t_fontStyleBox->addItem(FontStyleToStr(QFont::StyleItalic));
    ui->t_fontStyleBox->addItem(FontStyleToStr(QFont::StyleNormal));
    ui->t_fontStyleBox->addItem(FontStyleToStr(QFont::StyleOblique));
}

void Dialog::on_contactUs_clicked()
{
    QMessageBox::information(this, "Contact Us", "Email\nWillGetAnA@gmail.com\n\nPhone\n1-800-willgetana");
}

void Dialog::on_deleteButton_clicked()
{
    QSpinBox *idStore = ui->idSpinBox;
    ui->renderArea->deleteShape(idStore->value());
}


void Dialog::on_createEllipseButton_clicked() {
    QString penColorStr = ui->e_penColorBox->currentText();
    int penWidth = ui->e_penWidthBox->value();
    QString penStyleStr = ui->e_penStyleBox->currentText();
    QString penCapStyleStr = ui->e_penCapBox->currentText();
    QString penJoinStyleStr = ui->e_penJoinBox->currentText();
    QString brushColorStr = ui->e_brushColorBox->currentText();
    QString brushStyleStr = ui->e_brushStyleBox->currentText();
    QString dimensionsStr = ui->e_dim->text();

    ui->renderArea->addEllipse(penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr, brushColorStr, brushStyleStr, dimensionsStr);
}


void Dialog::on_createLineButton_clicked()
{
    QString penColorStr = ui->l_penColorBox->currentText();
    int penWidth = ui->l_penWidthBox->value();
    QString penStyleStr = ui->l_penStyleBox->currentText();
    QString penCapStyleStr = ui->l_penCapBox->currentText();
    QString penJoinStyleStr = ui->l_penJoinBox->currentText();
    QString dimensionsStr = ui->l_dim->text();

    ui->renderArea->addLine(penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr, dimensionsStr);
}


void Dialog::on_createTextButton_clicked()
{
    QString textContents = ui->t_textBox->text();
    QString textColorStr = ui->t_textColorBox->currentText();
    QString textAlignStr = ui->t_textAlignBox->currentText();
    int pointSize = ui->t_fontSizeBox->value();
    QString fontFamilyStr = ui->t_fontFamilyBox->text();
    QString fontStyleStr = ui->t_fontStyleBox->currentText();
    QString fontWeightStr = ui->t_fontWeightBox->currentText();
    QString dimensionsStr = ui->t_dim->text();

    ui->renderArea->addText(textContents, textColorStr, textAlignStr, pointSize, fontFamilyStr, fontStyleStr, fontWeightStr, dimensionsStr);
}


void Dialog::on_createRectButton_clicked()
{
    QString penColorStr = ui->r_penColorBox->currentText();
    int penWidth = ui->r_penWidthBox->value();
    QString penStyleStr = ui->r_penStyleBox->currentText();
    QString penCapStyleStr = ui->r_penCapBox->currentText();
    QString penJoinStyleStr = ui->r_penJoinBox->currentText();
    QString brushColorStr = ui->r_brushColorBox->currentText();
    QString brushStyleStr = ui->r_brushStyleBox->currentText();
    QString dimensionsStr = ui->r_dim->text();

    ui->renderArea->addRectangle(penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr, brushColorStr, brushStyleStr, dimensionsStr);
}


void Dialog::on_createPolygonButton_clicked()
{
    QString penColorStr = ui->pg_penColorBox->currentText();
    int penWidth = ui->pg_penWidthBox->value();
    QString penStyleStr = ui->pg_penStyleBox->currentText();
    QString penCapStyleStr = ui->pg_penCapBox->currentText();
    QString penJoinStyleStr = ui->pg_penJoinBox->currentText();
    QString brushColorStr = ui->pg_brushColorBox->currentText();
    QString brushStyleStr = ui->pg_brushStyleBox->currentText();
    QString dimensionsStr = ui->pg_dim->text();

    ui->renderArea->addPolygon(penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr, brushColorStr, brushStyleStr, dimensionsStr);
}


void Dialog::on_createPolylineButton_clicked()
{
    QString penColorStr = ui->pl_penColorBox->currentText();
    int penWidth = ui->pl_penWidthBox->value();
    QString penStyleStr = ui->pl_penStyleBox->currentText();
    QString penCapStyleStr = ui->pl_penCapBox->currentText();
    QString penJoinStyleStr = ui->pl_penJoinBox->currentText();
    QString dimensionsStr = ui->pl_dim->text();

    ui->renderArea->addPolyline(penColorStr, penWidth, penStyleStr, penCapStyleStr, penJoinStyleStr, dimensionsStr);
}


void Dialog::on_saveButton_clicked()
{
    ui->renderArea->Save();
}


void Dialog::on_moveButton_clicked()
{
    ui->renderArea->MoveShape(ui->moveID->value(), ui->moveDim->text());
}

