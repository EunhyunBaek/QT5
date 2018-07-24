/*
\#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
*/
#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.resize(500,500);
    w.show();
    return a.exec();
}
