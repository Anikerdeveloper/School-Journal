#include "authtorizationui.h"
#include "ui_authtorizationui.h"
#include "mainw.h"

#include <QDebug>

QString LoginP = "Admin";
QString PassP = "AdminPassword";

AuthtorizationUI::AuthtorizationUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthtorizationUI)
{
    ui->setupUi(this);
}

AuthtorizationUI::~AuthtorizationUI()
{
    delete ui;
}

void AuthtorizationUI::on_Auth_Button_clicked()
{
    qDebug() << "Логин - " << ui->Login->text() << "\n" << "Пароль - " << ui->Password->text();
    if (ui->Login->text() == LoginP && ui->Password->text() == PassP) {
        MainW mw;
        mw.show();
        mw.exec();
    }
}
