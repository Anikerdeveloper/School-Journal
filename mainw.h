#ifndef MAINW_H
#define MAINW_H

#include <QDialog>

namespace Ui {
class MainW;
}

class MainW : public QDialog
{
    Q_OBJECT

public:
    explicit MainW(QWidget *parent = nullptr);
    ~MainW();

    void SetData();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainW *ui;
};

#endif // MAINW_H
