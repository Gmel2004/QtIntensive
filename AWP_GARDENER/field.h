#ifndef FIELD_H
#define FIELD_H

#include <QDialog>
#include <grass.h>

namespace Ui {
class Field;
}

class Field : public QDialog
{
    Q_OBJECT

public:
    explicit Field(QWidget *parent = nullptr);
    ~Field();

private slots:
    void on_pushButton_clicked();
    void GoToGrass(QString num);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Field *ui;
};

#endif // FIELD_H
