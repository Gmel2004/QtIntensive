#include "grass.h"
#include "ui_grass.h"

Grass::Grass(QString num, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grass)
{
    ui->setupUi(this);
    setFixedSize(600, 600);
    QPixmap bkgnd(":/Grass.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
    this->num = num;
    setWindowTitle("Грядка " + num);
    QFile file("./" + num + ".txt");
    file.open(QIODevice::ReadOnly|QFile::Text);
    QString information = file.readAll();
    QString curDel = "";
    for (int i = 1; i < information.length(); i++) {
        if (information[i] != ' ') {
            curDel += information[i];
        }
        else {
            DelList.append(curDel);
            curDel = "";
        }
    }
    if (curDel != "") {
        DelList.append(curDel);
    }
    file.close();
}

Grass::~Grass()
{
    delete ui;
}

void Grass::GoToField() {
    QWidget *m_Field = new Field();
    m_Field->show();
    close();
}

void Grass::on_backButton_clicked()
{
    GoToField();
}


void Grass::on_pushButton_clicked()
{
    QString addDel = ui->lineEdit->text();
    if (DelList.count(addDel)) {
        QMessageBox::critical(this, "Ошибка", "Указаное растение существует!");
    }
    else if (addDel == "" || addDel.contains(' ')) {
        QMessageBox::critical(this, "Ошибка", "Невозможное название для растения! Строка не должна являться пустой и содержать пробелов");
    }
    else if (DelList.length() >= 5) {
        QMessageBox::critical(this, "Ошибка", "Невозможно посадить. Максимальное количесво растений!");
    }
    else {
        DelList.append(ui->lineEdit->text());
        SaveToFile();
        QMessageBox::information(this, "", "Растение успешно посажено!");
    }
}


void Grass::on_popButton_clicked()
{
    QString dd = ui->lineEdit->text();
    bool isErased = false;
    for (auto i = DelList.begin(); i != DelList.end() && !isErased; i++) {
        if (*i == dd) {
            isErased = true;
            DelList.erase(i);
        }
    }
    if (!isErased) {
        QMessageBox::critical(this, "Ошибка", "Растение не найдено!");
    }
    else {
        SaveToFile();
        QMessageBox::information(this, "", "Растение успешно выкопано!");
    }
}


void Grass::on_infoButton_clicked()
{
    QWidget *m_information = new Information(num, this);
    m_information->show();
    hide();
}

void Grass::SaveToFile() {
    QFile file("./" + num + ".txt");
    file.open(QIODevice::WriteOnly);
    for (int i = 0; i < DelList.length(); i++) {
        file.write((" " + DelList[i]).toStdString().data());
    }
    file.close();
}

