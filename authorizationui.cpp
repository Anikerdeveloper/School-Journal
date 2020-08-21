#include "authorizationui.h"
#include "ui_authorizationui.h"
#include "mainw.h"
#include "dataofstudent.h"

#include <QDebug>

QString LoginP = "Admin";
QString PassP = "AdminPassword";
bool EchoIsNormal = false;

AuthorizationUI::AuthorizationUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorizationUI)
{
    ui->setupUi(this);
}

AuthorizationUI::~AuthorizationUI()
{
    delete ui;
}

void AuthorizationUI::on_Auth_Button_clicked()
{
    DataOfStudent dof;
    qDebug() << "Логин - " << ui->Login->text() << "\n" << "Пароль - " << ui->Password->text();
    if (dof.AuthtorizationStudent(ui->Login->text(), ui->Password->text()) /*ui->Login->text() == LoginP && ui->Password->text() == PassP*/) {
        MainW mw;
        mw.show();
        mw.SetData();
        mw.exec();
    }
}

void AuthorizationUI::on_pushButton_clicked()
{
    switch (EchoIsNormal) {
    case 0:
        EchoIsNormal = true;
        ui->Password->setEchoMode(QLineEdit::Normal);
        break;
    case 1:
        EchoIsNormal = false;
        ui->Password->setEchoMode(QLineEdit::Password);
        break;
    }
}
