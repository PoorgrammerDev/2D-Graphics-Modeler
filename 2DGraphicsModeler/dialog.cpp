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



void Dialog::on_pushButton_5_clicked()
{
    ui->stackedWidget->addWidget(ui->Line);
    ui->stackedWidget->setCurrentWidget(ui->Line);
    ui->comboBox_4->addItem("a");
    ui->comboBox_5->addItem("a");
    ui->comboBox_6->addItem("a");
}

void Dialog::on_pushButton_4_clicked()
{
    ui->stackedWidget->addWidget(ui->Text);
    ui->stackedWidget->setCurrentWidget(ui->Text);
    ui->comboBox_7->addItem("adfs");
    ui->comboBox_8->addItem("sdfa");
    ui->comboBox_9->addItem("dfsa");
}

void Dialog::on_pushButton_3_clicked()
{
    ui->stackedWidget->addWidget(ui->Rectangle);
    ui->stackedWidget->setCurrentWidget(ui->Rectangle);
    ui->comboBox_10->addItem("afsd");
    ui->comboBox_11->addItem("fsda");
    ui->comboBox_12->addItem("fsda");
}

void Dialog::on_pushButton_6_clicked()
{
    ui->stackedWidget->addWidget(ui->Polygon);
    ui->stackedWidget->setCurrentWidget(ui->Polygon);
    ui->comboBox_13->addItem("fsda");
    ui->comboBox_14->addItem("fsad");
    ui->comboBox_15->addItem("fsda");


}

void Dialog::on_pushButton_9_clicked()
{
    ui->stackedWidget->addWidget(ui->Ellipse);
    ui->stackedWidget->setCurrentWidget(ui->Ellipse);
    ui->comboBox_16->addItem("fsad");
    ui->comboBox_17->addItem("fsad");
    ui->comboBox_18->addItem("fasd");
}

void Dialog::on_pushButton_10_clicked()
{
    ui->stackedWidget->addWidget(ui->Polyline);
    ui->stackedWidget->setCurrentWidget(ui->Polyline);
    ui->comboBox->addItem("sdfa");
    ui->comboBox_2->addItem("fsda");
    ui->comboBox_3->addItem("sdfa");
}
