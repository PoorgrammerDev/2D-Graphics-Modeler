#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPixmap>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    //Shape Selection (Right Column)
    void on_shSelLine_clicked();
    void on_shSelText_clicked();
    void on_shSelRect_clicked();
    void on_shSelPolygon_clicked();
    void on_shSelEllipse_clicked();
    void on_shSelPolyline_clicked();

    void on_contactUs_clicked();

    void on_deleteButton_clicked();

    void on_createEllipseButton_clicked();

    void on_createLineButton_clicked();

    void on_createTextButton_clicked();

    void on_createRectButton_clicked();

    void on_createPolygonButton_clicked();

    void on_createPolylineButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::Dialog *ui;
    void AddFieldValues();
};

#endif // DIALOG_H
