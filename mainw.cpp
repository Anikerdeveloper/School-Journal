#include "mainw.h"
#include "ui_mainw.h"

MainW::MainW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainW)
{
    ui->setupUi(this);
}

MainW::~MainW()
{
    delete ui;
}

void MainW::on_pushButton_clicked()
{
    ui->MainWidget->setCurrentIndex(0);
}

void MainW::on_pushButton_2_clicked()
{
    ui->MainWidget->setCurrentIndex(1);
}
