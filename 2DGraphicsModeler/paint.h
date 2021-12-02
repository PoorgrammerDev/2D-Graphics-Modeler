#ifndef PAINT_H
#define PAINT_H

#include <QDialog>
#include <QMainWindow>
#include <QWidget>
#include <QListView>
#include <QComboBox>

namespace Ui {
class paint;
}

class paint : public QDialog
{
    Q_OBJECT

public:
    explicit paint(QWidget *parent = nullptr);
    ~paint();

private slots:


private:
    Ui::paint *ui;
};

#endif // PAINT_H
