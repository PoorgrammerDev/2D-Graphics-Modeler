#include "paint.h"
#include "ui_paint.h"

paint::paint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paint)
{
    ui->setupUi(this);




}

paint::~paint()
{
    delete ui;
}



