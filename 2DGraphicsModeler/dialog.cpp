#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_shSelLine_clicked()
{
    ui->shapeBuilder->addWidget(ui->Line);
    ui->shapeBuilder->setCurrentWidget(ui->Line);
    ui->l_penStyleBox->addItem("");
    ui->l_penCapBox->addItem("");
    ui->l_penJoinBox->addItem("");
}

void Dialog::on_shSelText_clicked()
{
    ui->shapeBuilder->addWidget(ui->Text);
    ui->shapeBuilder->setCurrentWidget(ui->Text);
    ui->t_fontFamilyBox->addItem("");
    ui->t_fontStyleBox->addItem("");
    ui->t_penJoinBox->addItem("");
}

void Dialog::on_shSelRect_clicked()
{
    ui->shapeBuilder->addWidget(ui->Rectangle);
    ui->shapeBuilder->setCurrentWidget(ui->Rectangle);
    ui->r_penCapBox->addItem("");
    ui->r_penJoinBox->addItem("");
    ui->r_penStyleBox->addItem("");
}

void Dialog::on_shSelPolygon_clicked()
{
    ui->shapeBuilder->addWidget(ui->Polygon);
    ui->shapeBuilder->setCurrentWidget(ui->Polygon);
    ui->pg_fillColorBox->addItem("");
    ui->pg_fillStyleBox->addItem("");
    ui->pg_penCapBox->addItem("");
    ui->pg_penJoinBox->addItem("");
    ui->pg_penStyleBox->addItem("");

}

void Dialog::on_shSelEllipse_clicked()
{
    ui->shapeBuilder->addWidget(ui->Ellipse);
    ui->shapeBuilder->setCurrentWidget(ui->Ellipse);
    ui->e_penCapBox->addItem("");
    ui->e_penJoinBox->addItem("");
    ui->e_penStyleBox->addItem("");
}

void Dialog::on_shSelPolyline_clicked()
{
    ui->shapeBuilder->addWidget(ui->Polyline);
    ui->shapeBuilder->setCurrentWidget(ui->Polyline);
    ui->pl_penCapBox->addItem("");
    ui->pl_penJoinBox->addItem("");
    ui->pl_penStyleBox->addItem("");
}
