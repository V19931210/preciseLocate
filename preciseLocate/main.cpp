#include "preciseLocate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    preciseLocate w;
    w.show();
    return a.exec();
}
