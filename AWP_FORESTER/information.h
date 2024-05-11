#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include <QFile>
#include <map.h>

namespace Ui {
class Information;
}

class Information : public QDialog
{
    Q_OBJECT

public:
    explicit Information(QString Log, QString NumKvart, QString NumDel, QWidget *parent = nullptr);
    ~Information();

private slots:
    void on_BackButton_clicked();

    void on_SaveButton_clicked();

private:
    Ui::Information *ui;
    QWidget *parent = nullptr;
    QString Log;
    QString NumKvart;
    QString NumDel;
};

#endif // INFORMATION_H
