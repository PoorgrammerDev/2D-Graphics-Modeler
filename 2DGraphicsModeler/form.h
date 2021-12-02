#ifndef FORM_H
#define FORM_H

#include <QDialog>
#include <QMainWindow>
#include <QWidget>
#include <QListView>
#include <QComboBox>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
