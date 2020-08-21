#include "dataofstudent.h"
#include "TFR.h"
#include <QDebug>
#include <QMessageBox>

string ClassFile;
int StudentID;
Student studentdata;

TFR fr;

DataOfStudent::DataOfStudent()
{
}

bool DataOfStudent::AuthtorizationStudent(QString LoginS, QString PassS) {
    fr.TFRFile("C:/Git-Projects/School-Journal/AuthInfo.txt");

    int CountAccounts = fr.TagCount("Login");
    for (int i = 0; i < CountAccounts; i++) {
        if (QString::fromStdString(fr.ReadFromTag("Login")) == LoginS){
            if (QString::fromStdString(fr.GetLineOfAttribute("Password","ID", to_string(i))) == PassS) {
                StudentID = i;
                ClassFile = fr.GetLineOfAttribute("ClassFile","ID", to_string(i));
                fr.TFRFile("C:/Git-Projects/School-Journal/" + ClassFile);
                return true;
            }
        } else {
           //return false;
        }

    }
}

QString DataOfStudent::FullName() {
   studentdata.Name = QString::fromStdString(fr.GetLineOfAttribute("Name","ID", to_string(StudentID)));
   studentdata.LastName = QString::fromStdString(fr.GetLineOfAttribute("LastName","ID", to_string(StudentID)));
   studentdata.MiddleName = QString::fromStdString(fr.GetLineOfAttribute("MiddleName","ID", to_string(StudentID)));

   if (studentdata.Name.length() + studentdata.LastName.length() <= 13) {
       return studentdata.Name + " " + studentdata.LastName + "\n" + studentdata.MiddleName;
   } else {
       return studentdata.Name + " " + studentdata.LastName + " " + studentdata.MiddleName;
   }
}
