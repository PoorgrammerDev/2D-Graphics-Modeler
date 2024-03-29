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
    delete dialog1;
}


void LoginApp::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "guest" && password == "guest")
    {
        hide();
        dialog1 = new Dialog(this);
        dialog1->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password is NOT correct. Try again");
    }

}


void LoginApp::on_hackButton_clicked()
{
    QMessageBox::information(this, "H4CK-L0G1N-F0UND",  "LOGIN: guest\nPASSWORD: guest");
}

