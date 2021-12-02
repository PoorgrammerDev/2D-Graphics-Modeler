#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}



void Form::on_pushButton_5_clicked()
{
    ui->stackedWidget->addWidget(ui->Polygon);
    ui->stackedWidget->setCurrentWidget(ui->Polygon);
}

void Form::on_pushButton_4_clicked()
{
    ui->stackedWidget->addWidget(ui->Line);
    ui->stackedWidget->setCurrentWidget(ui->Line);
}
