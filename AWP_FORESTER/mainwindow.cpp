#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file("./Users.json");
    setWindowTitle("Авторизация");
    file.open(QIODevice::ReadOnly|QFile::Text);
    doc = QJsonDocument::fromJson(QByteArray(file.readAll()), &docError);
    file.close();
    QJsonValue Users = doc.object().value("Users");
    docAr = QJsonValue(Users).toArray();
    json = docAr.at(0).toObject();
    QPixmap bkgnd(":/src/BackgroundAutorization.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
    setFixedSize(width(), height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::isLogValid()
{
    //Логин не менее 4 символов
    return Log.length() > 3;
}

bool MainWindow::isPasValid()
{
    return Pas.length() > 7;
}

void MainWindow::on_SignIn_clicked()
{
    Log = ui->InputLog->text();
    Pas = ui->InputPas->text();
    if (json.find(Log) != json.end()) {//если логин существует
        if (json.value(Log) == Pas) {//проверка сходимости паролей
            ToSystem();
        }
        else {
            QMessageBox::critical(this, "Ошибка", "Логин или пароль не верны!");
        }

    }
    else {
        QMessageBox::critical(this, "Ошибка", "Указанный логин не существует!");
    }
}


void MainWindow::on_SignUp_clicked()
{
    QFile file("./Users.json");
    Log = ui->InputLog_2->text();
    Pas = ui->InputPas_2->text();
    if (!isLogValid() && !isPasValid()) {
        char a[1000] = "Логин и пароль не корректны!\n\n"
                      "Логин должен:\n"
                      "৹ Содержать не менее 4 символов\n"
                       "Пароль должен:\n"
                       "৹ Содержать не менее 8 символов\n";
        QMessageBox::critical(this, "Ошибка", a);
    }
    else if (!isLogValid()) {
        char a[1000] = "Логин не корректен!\n\n"
                      "Логин должен:\n"
                      "৹ Содержать не менее 4 символов\n";
        QMessageBox::critical(this, "Ошибка", a);
    }
    else if (!isPasValid()) {
        char a[1000] = "Пароль не корректен!\n\n"
                       "Пароль должен:\n"
                       "৹ Содержать не менее 8 символов\n";
        QMessageBox::critical(this, "Ошибка", a);
    }
    else if (json.find(Log) == json.end()) {    //проверка на оригинальность логина
        file.open(QIODevice::WriteOnly);
        json.insert(Log, Pas);
        QJsonArray docToWrite = {};
        docToWrite.append(json);
        doc.setArray(docToWrite);
        file.write("{\"Users\":"+doc.toJson()+"}");
        file.close();
        QMessageBox::about(this, "Регистрация", "Регистрация прошла успешно!");
        ToSystem();
    }
    else {
        QMessageBox::critical(this, "Ошибка", "Логин уже используется!");

    }
}

void MainWindow::ToSystem() {
    QWidget *m_map = new Map(Log, this);
    m_map->show();
    hide();
}

