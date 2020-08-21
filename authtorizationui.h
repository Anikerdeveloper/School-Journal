#ifndef AUTHTORIZATIONUI_H
#define AUTHTORIZATIONUI_H

#include <QDialog>

namespace Ui {
class AuthtorizationUI;
}

class AuthtorizationUI : public QDialog
{
    Q_OBJECT

public:
    explicit AuthtorizationUI(QWidget *parent = nullptr);
    ~AuthtorizationUI();

private slots:
    void on_Auth_Button_clicked();

    void on_pushButton_clicked();

private:
    Ui::AuthtorizationUI *ui;
};

#endif // AUTHTORIZATIONUI_H
