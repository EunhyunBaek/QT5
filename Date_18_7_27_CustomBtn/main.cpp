#include "widget.h"
#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel *hello = new QLabel("hello qt!",0,Qt::FramelessWindowHint);
    hello->showMaximized();
    Widget w;
    w.show();

    return a.exec();
}
