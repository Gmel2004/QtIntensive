#include "information.h"
#include "ui_information.h"

Information::Information(QString Log, QString NumKvart, QString NumDel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/src/BackgroundAutorization.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
    setWindowTitle("Информация о делянке");
    if (parent != nullptr) {
        setGeometry(parent->geometry());
        setFixedSize(parent->width(), parent->height());
        this->parent = parent;
    }
    this->Log = Log;
    this->NumKvart = NumKvart;
    this->NumDel = NumDel;
    QFile file("./" + Log + NumKvart + NumDel + ".txt");
    file.open(QIODevice::ReadOnly|QFile::Text);
    QString information = file.readAll();
    file.close();
    ui->textEdit->setText(information);
}

Information::~Information()
{
    delete ui;
}

void Information::on_BackButton_clicked()
{
    if (parent != nullptr) {
        parent->show();
        close();
    }
}


void Information::on_SaveButton_clicked()
{
    QFile file("./" + Log + NumKvart + NumDel + ".txt");
    file.open(QIODevice::WriteOnly);
    file.write(ui->textEdit->toPlainText().toStdString().data());
    file.close();
}

