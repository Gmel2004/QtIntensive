#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QMap>
#include <QFile>
#include <QJsonObject>
#include <QFileDialog>
#include <QStandardItem>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <map.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QJsonDocument doc;
    QJsonArray docAr;
    QJsonParseError docError;
    QJsonObject UsersDataJson;
    QJsonObject json;

private:
    Ui::MainWindow *ui;
    void ToSystem();
    QString Log, Pas;
    QMap<QString, QString> UsersData;
    bool isLogValid();
    bool isPasValid();

private slots:
    void on_SignIn_clicked();

    void on_SignUp_clicked();
};
#endif // MAINWINDOW_H
