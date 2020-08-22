#ifndef DATAOFSTUDENT_H
#define DATAOFSTUDENT_H
#include <QString>
#include <vector>
#include <QTableWidget>

struct Subject {
    QString NameSubject;
    QString Appraisals;
};

struct StudentTimeTable {
    QString STB[7][6];
};

struct Student {
    QString Name;
    QString LastName;
    QString MiddleName;
    QString StudentClass;
    StudentTimeTable stb;
    std::vector<Subject> AcademicSubjects;
};

class DataOfStudent
{
public:
    DataOfStudent();

    bool AuthtorizationStudent(QString LoginS, QString PassS);
    static QString FullName();
    void SetTimeTable(QTableWidget &qtw);
};

#endif // DATAOFSTUDENT_H
