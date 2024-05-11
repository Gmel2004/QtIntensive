#include "information.h"
#include "ui_information.h"

Information::Information(QString num, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information)
{
    ui->setupUi(this);
    setFixedSize(600, 600);
    this->parent = parent;
    QPixmap bkgnd(":/Grass.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
    setWindowTitle("Информация");
    this->num = num;
    QFile file("./" + num + ".txt");
    file.open(QIODevice::ReadOnly|QFile::Text);
    QString information = file.readAll();
    information.replace(' ', '\n');
    ui->label->setText("Растения: " + information);
}

Information::~Information()
{
    delete ui;
}

void Information::GoToGrass() {
    parent->show();
    close();
}

void Information::on_backButton_clicked()
{
    GoToGrass();
}

