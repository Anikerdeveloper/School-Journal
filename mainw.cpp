#include "mainw.h"
#include "ui_mainw.h"
#include "dataofstudent.h"
#include <QDebug>
#include <QTableWidget>

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

void MainW::SetData() {
    DataOfStudent dof;
    ui->StudentName->setText(dof.FullName());
    dof.SetTimeTable(*ui->Timetable);


}
