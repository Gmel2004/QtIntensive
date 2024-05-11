#include "field.h"
#include "ui_field.h"

Field::Field(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Field)
{
    ui->setupUi(this);
    setFixedSize(600, 600);
    QPixmap bkgnd(":/Grass.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
    setWindowTitle("Поле");
}

Field::~Field()
{
    delete ui;
}

void Field::GoToGrass(QString num) {
    QWidget *m_grass = new Grass(num);
    m_grass->show();
    close();
}

void Field::on_pushButton_clicked()
{
    GoToGrass("1");
}


void Field::on_pushButton_2_clicked()
{
    GoToGrass("2");
}


void Field::on_pushButton_3_clicked()
{
    GoToGrass("3");
}


void Field::on_pushButton_4_clicked()
{
    GoToGrass("4");
}

