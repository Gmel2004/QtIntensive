#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include <kvart.h>

namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QString Log, QWidget *parent = nullptr);
    ~Map();

private slots:
    void on_BackButton_clicked();

    void on_Area1_clicked();

    void on_Area2_clicked();

    void on_Area3_clicked();

    void on_Area4_clicked();

    void on_Area5_clicked();

    void on_Area6_clicked();

private:
    Ui::Map *ui;
    QWidget *parent = nullptr;
    QString Log;
};

#endif // MAP_H
