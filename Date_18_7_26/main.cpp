#include "qtediter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtEditer w;
    w.show();

    return a.exec();
}
