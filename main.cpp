#include "authtorizationui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthtorizationUI aui;
    aui.show();
    return a.exec();
}
