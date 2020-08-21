#include "authorizationui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthorizationUI aui;
    aui.show();
    return a.exec();
}
