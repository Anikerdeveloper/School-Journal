#include "dataofstudent.h"
#include "TFR.h"
#include <QDebug>
#include <QMessageBox>

TFR fr;

string ClassFile;
int StudentID;

Student studentdata;

DataOfStudent::DataOfStudent()
{
    fr.TFRFile("C:/Git-Projects/School-Journal/AuthInfo.txt");
}

bool DataOfStudent::AuthtorizationStudent(QString LoginS, QString PassS) {
    int CountAccounts = fr.TagCount("Login");
    for (int i = 0; i < CountAccounts; i++) {

        if (QString::fromStdString(fr.ReadFromTag("Login")) == LoginS){
            qDebug() << "Логин существует" << "\n";
            if (QString::fromStdString(fr.GetLineOfAttribute("Password","ID", to_string(i))) == PassS) {
                qDebug() << "Пароль верный";
                StudentID = i;
                ClassFile = fr.GetLineOfAttribute("ClassFile","ID",to_string(i));
                fr.TFRFile("C:/Git-Projects/School-Journal/" + ClassFile);
                qDebug() << "C:/Git-Projects/School-Journal/" + QString::fromStdString(ClassFile);
                return true;
            }
        } else {
           qDebug() << "логина нет";
           return false;
        }

    }
}

QString DataOfStudent::FullName() {
   studentdata.Name = QString::fromStdString(fr.GetLineOfAttribute("Name","ID", to_string(StudentID)));
   studentdata.LastName = QString::fromStdString(fr.GetLineOfAttribute("LastName","ID", to_string(StudentID)));
   studentdata.MiddleName = QString::fromStdString(fr.GetLineOfAttribute("MiddleName","ID", to_string(StudentID)));
   return studentdata.Name;
}
