#ifndef DATAOFSTUDENT_H
#define DATAOFSTUDENT_H
#include <QString>
#include <vector>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

struct Subject {
    QString NameSubject;
    QString Appraisals;
};

struct Student {
    QString Name;
    QString LastName;
    QString MiddleName;
    QString StudentClass;
    std::vector<Subject> AcademicSubjects;
};

class DataOfStudent
{
public:
    DataOfStudent();

    bool AuthtorizationStudent(QString LoginS, QString PassS);
    static QString FullName();
    void SetTimeTable(QTableWidget &qtw);
    void SetEstimatesTable(QTableWidget &qtw);
};

#endif // DATAOFSTUDENT_H
