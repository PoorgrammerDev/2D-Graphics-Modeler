#include "loginapp.h"
#include "ui_loginapp.h"
#include <QMessageBox>

LoginApp::LoginApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginApp)
{
    ui->setupUi(this);
}

LoginApp::~LoginApp()
{
    delete ui;
}



void LoginApp::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "guest" && password == "guest")
    {
        //QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        paint1 = new paint(this);
        paint1->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password is NOT correct. Try again");
    }

}

