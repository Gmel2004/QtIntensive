#ifndef INFORMATION_H
#define INFORMATION_H

#include <QDialog>
#include <QFile>

namespace Ui {
class Information;
}

class Information : public QDialog
{
    Q_OBJECT

public:
    QWidget *parent;
    explicit Information(QString num, QWidget *parent = nullptr);
    ~Information();

private slots:
    void on_backButton_clicked();

    void GoToGrass();

private:
    Ui::Information *ui;
    QString num;
};

#endif // INFORMATION_H
