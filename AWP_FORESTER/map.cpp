#include "map.h"
#include "ui_map.h"

Map::Map(QString Log, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
    if (parent != nullptr) {
        setGeometry(parent->geometry());
        setFixedSize(parent->width(), parent->height());
        this->parent = parent;
    }
    QPixmap bkgnd(":/src/BackgroundAutorization.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
    setWindowTitle("Карта местности");
    this->Log = Log;
}

Map::~Map()
{
    delete ui;
}

void Map::on_BackButton_clicked()
{
    if (parent != nullptr) {
        parent->show();
        close();
    }
}

void Map::on_Area1_clicked()
{
    Kvart* m_kvart = new Kvart(Log, 1, this);
    m_kvart->show();
    hide();
}


void Map::on_Area2_clicked()
{
    Kvart* m_kvart = new Kvart(Log, 2, this);
    m_kvart->show();
    hide();
}


void Map::on_Area3_clicked()
{
    Kvart* m_kvart  = new Kvart(Log, 3, this);
    m_kvart->show();
    hide();
}


void Map::on_Area4_clicked()
{
    Kvart* m_kvart = new Kvart(Log, 4, this);
    m_kvart->show();
    hide();
}


void Map::on_Area5_clicked()
{
    Kvart* m_kvart = new Kvart(Log, 5, this);
    m_kvart->show();
    hide();
}


void Map::on_Area6_clicked()
{
    Kvart* m_kvart = new Kvart(Log, 6, this);
    m_kvart->show();
    hide();
}

