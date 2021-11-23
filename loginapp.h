#ifndef LOGINAPP_H
#define LOGINAPP_H

#include <QMainWindow>
#include "paint.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginApp; }
QT_END_NAMESPACE

class LoginApp : public QMainWindow
{
    Q_OBJECT

public:
    LoginApp(QWidget *parent = nullptr);
    ~LoginApp();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::LoginApp *ui;
    paint *paint1;
};
#endif // LOGINAPP_H
