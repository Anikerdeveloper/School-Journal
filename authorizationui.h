#ifndef AUTHTORIZATIONUI_H
#define AUTHTORIZATIONUI_H

#include <QDialog>

namespace Ui {
class AuthorizationUI;
}

class AuthorizationUI : public QDialog
{
    Q_OBJECT

public:
    explicit AuthorizationUI(QWidget *parent = nullptr);
    ~AuthorizationUI();

private slots:
    void on_Auth_Button_clicked();

    void on_pushButton_clicked();

private:
    Ui::AuthorizationUI *ui;
};

#endif // AUTHTORIZATIONUI_H
