#include "authtorizationui.h"
#include "ui_authtorizationui.h"
#include "mainw.h"
#include "dataofstudent.h"

#include <QDebug>

QString LoginP = "Admin";
QString PassP = "AdminPassword";
bool EchoIsNormal = false;

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
    DataOfStudent dof;
    qDebug() << "Логин - " << ui->Login->text() << "\n" << "Пароль - " << ui->Password->text();
    if (dof.AuthtorizationStudent(ui->Login->text(), ui->Password->text()) /*ui->Login->text() == LoginP && ui->Password->text() == PassP*/) {
        MainW mw;
        mw.show();
        mw.SetData();
        mw.exec();
    }
}

void AuthtorizationUI::on_pushButton_clicked()
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
