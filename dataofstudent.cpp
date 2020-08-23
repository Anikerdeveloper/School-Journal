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
        qDebug() << i;

        if (QString::fromStdString(fr.GetLineOfAttribute("Login","ID", to_string(i))) == LoginS){
            if (QString::fromStdString(fr.GetLineOfAttribute("Password","ID", to_string(i))) == PassS) {
                StudentID = i;
                ClassFile = fr.GetLineOfAttribute("ClassFile","ID", to_string(i));
                fr.TFRFile("C:/Git-Projects/School-Journal/" + ClassFile);
                return true;
            } else {
                return false;
             }
        }
    }
}

QString DataOfStudent::FullName() {
   studentdata.Name = QString::fromStdString(fr.GetLineOfAttribute("Name","ID", to_string(StudentID)));
   studentdata.LastName = QString::fromStdString(fr.GetLineOfAttribute("LastName","ID", to_string(StudentID)));
   studentdata.MiddleName = QString::fromStdString(fr.GetLineOfAttribute("MiddleName","ID", to_string(StudentID)));

   if (studentdata.Name.length() + studentdata.LastName.length() <= 13) {
       return studentdata.LastName + " " + studentdata.Name + "\n" + studentdata.MiddleName;
   } else {
       return studentdata.LastName + " " + studentdata.Name + " " + studentdata.MiddleName;
   }
}

void DataOfStudent::SetTimeTable(QTableWidget &qtw) {
    string AttributeN[2] = {"DayNumber","LessonNumber"};
    string AttributeV[2] = {"0","1"};
    for(int i = 0; i < 6; i++)//урок
    {
        for(int y = 0; y < 7; y++)//день
        {
            AttributeV[0] = to_string(i);
            AttributeV[1] = to_string(y);
            qtw.setItem(y, i, new QTableWidgetItem(QString::fromStdString(fr.GetFromMultipleTags(2,"TimetableC",AttributeN,AttributeV))));

        }
    }
}

void DataOfStudent::SetEstimatesTable(QTableWidget &qtw) {

    qtw.setRowCount(fr.TagCount("LessonName"));
    for (int i = 0; i < fr.TagCount("LessonName"); i++)
    {
        qtw.setItem(i,0, new QTableWidgetItem(QString::fromStdString(fr.GetLineOfAttribute("LessonName","Lesson",to_string(i)))));
    }

    string NameAS[2] = {"Lesson","ID"};
    string ValueAS[2] = {"", to_string(StudentID)};

    for (int i = 0; i < fr.TagCount("LessonName"); i++)
    {
        ValueAS[0] = to_string(i);
        qtw.setItem(i,1, new QTableWidgetItem(QString::fromStdString(fr.GetFromMultipleTags(2,"LessonEstimates",NameAS,ValueAS))));
    }

    string Buff;
    string C;
    float AverageScore = 0;

    for (int i = 0; i < fr.TagCount("LessonName"); i++)
    {
        AverageScore = 0;
        ValueAS[0] = to_string(i);
        Buff = fr.GetFromMultipleTags(2,"LessonEstimates",NameAS,ValueAS);
        for (int y = 0; y < Buff.length(); y++)
        {
            C = Buff[y];
            AverageScore += stoi(C);
            cout << AverageScore << "-";
        }
        cout << endl;
        AverageScore = AverageScore / Buff.length();
        qtw.setItem(i,2, new QTableWidgetItem(QString::number(AverageScore)));
    }

    qtw.resizeColumnsToContents();
}
