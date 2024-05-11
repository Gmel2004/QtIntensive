#ifndef GRASS_H
#define GRASS_H

#include <QDialog>
#include <field.h>
#include <information.h>
#include <QMessageBox>
#include <QFile>

namespace Ui {
class Grass;
}

class Grass : public QDialog
{
    Q_OBJECT

public:
    explicit Grass(QString num, QWidget *parent = nullptr);
    ~Grass();

private slots:
    void on_backButton_clicked();

    void on_pushButton_clicked();

    void on_popButton_clicked();

    void GoToField();

    void on_infoButton_clicked();

    void SaveToFile();

private:
    Ui::Grass *ui;
    QList<QString> DelList;
    QString num;
};

#endif // GRASS_H
