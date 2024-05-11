#ifndef KVART_H
#define KVART_H

#include <QDialog>
#include <information.h>
#include <QMessageBox>

namespace Ui {
class Kvart;
}

class Kvart : public QDialog
{
    Q_OBJECT

public:
    explicit Kvart(QString Log, int number, QWidget *parent = nullptr);
    ~Kvart();

private slots:
    void on_InformationButton_clicked();

    void on_AddButton_clicked();

    void on_DelButton_clicked();

    void SaveToFile();

    void UpdateComboBox();

    void on_BackButton_clicked();

private:
    Ui::Kvart *ui;
    QWidget *parent = nullptr;
    QString numberD;
    QString Log;
    QList<QString> DelList;
};

#endif // KVART_H
