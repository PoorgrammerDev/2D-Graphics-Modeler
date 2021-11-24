#ifndef PAINT_H
#define PAINT_H

#include <QDialog>

namespace Ui {
class paint;
}

class paint : public QDialog
{
    Q_OBJECT

public:
    explicit paint(QWidget *parent = nullptr);
    ~paint();

private:
    Ui::paint *ui;
};

#endif // PAINT_H
