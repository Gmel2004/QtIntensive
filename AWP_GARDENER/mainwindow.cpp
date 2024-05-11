#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600, 600);
    QPixmap bkgnd(":/Grass.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    setPalette(palette);
    setWindowTitle("Загрузка");
    ui->progressBar->setValue(0);
    ui->progressBar->hide();
    ui->label->hide();
    ui->label_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->progressBar->show();
    ui->label->show();
    ui->pushButton->hide();
    ui->label_2->show();
    ui->label_2->setText("0%");
    int dop = 0;
    while(ui->progressBar->value() < 100) {
        if (dop == 10000000) {
            ui->progressBar->setValue(ui->progressBar->value() + 1);
            dop = 0;
            ui->label_2->setText(QString::number(ui->progressBar->value()) + "%");
        }
        else {
            dop += 1;
        }

    }
    QWidget *m_Fild = new Field();
    m_Fild->show();
    close();
}

