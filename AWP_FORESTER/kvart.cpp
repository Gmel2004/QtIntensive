#include "kvart.h"
#include "ui_kvart.h"

Kvart::Kvart(QString Log, int number, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kvart)
{
    ui->setupUi(this);
    setWindowTitle("Кваратал " + QString::number(number));
    QPixmap bkgnd(":/src/BackgroundAutorization.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
    setFixedSize(size());
    if (parent != nullptr) {
        this->parent = parent;
    }
    numberD = QString::number(number);
    this->Log = Log;
    QFile file("./" + Log + numberD + ".txt");
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
    UpdateComboBox();
    if (parent != nullptr) {
        setGeometry(parent->geometry());
        setFixedSize(parent->width(), parent->height());
        this->parent = parent;
    }
}

Kvart::~Kvart()
{
    delete ui;
}

void Kvart::UpdateComboBox() {
    ui->comboBox->clear();
    for (int i = 0; i < DelList.length(); i++) {
        ui->comboBox->insertItem(ui->comboBox->count(), DelList[i]);
    }
    ui->comboBox->update();
}

void Kvart::on_InformationButton_clicked()
{
    QWidget *inf = new Information(Log, numberD, ui->comboBox->currentText(), this);
    inf->show();
    hide();
}

void Kvart::on_AddButton_clicked()
{
    QString addDel = ui->lineEdit->text();
    if (DelList.count(addDel)) {
        QMessageBox::critical(this, "Ошибка", "Указана делянка существует!");
    }
    else if (addDel == "" || addDel.contains(' ')) {
        QMessageBox::critical(this, "Ошибка", "Невозможное название делянки! Строка не должна являться пустой и содержать пробелов");
    }
    else if (DelList.length() >= 5) {
        QMessageBox::critical(this, "Ошибка", "Невозможно добавить. Максимальное количесво делянок в квартале!");
    }
    else {
        DelList.append(ui->lineEdit->text());
        SaveToFile();
        UpdateComboBox();
        QMessageBox::information(this, "", "Делянка успешно добавлена!");
    }
}

void Kvart::SaveToFile() {
    QFile file("./" + Log + numberD + ".txt");
    file.open(QIODevice::WriteOnly);
    for (int i = 0; i < DelList.length(); i++) {
        file.write((" " + DelList[i]).toStdString().data());
    }
    file.close();
}

void Kvart::on_DelButton_clicked()
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
        QMessageBox::critical(this, "Ошибка", "Делянка не найдена!");
    }
    else {
        SaveToFile();
        UpdateComboBox();
        QMessageBox::information(this, "", "Делянка успешно удалена!");
    }
}


void Kvart::on_BackButton_clicked()
{
    parent->show();
    this->close();
}

