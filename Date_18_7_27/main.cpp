#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
void H_QTranslator(){

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;
    QString lang = QLocale::system().uiLanguages().first();

    //translator.load("hello_"+lang.left(2));
    translator.load("hello_ko");
    a.installTranslator(&translator);

    QPushButton hello(QObject::tr("Hello world"));
    hello.resize(100,30);
    hello.show();
    MainWindow w;
    w.show();

    return a.exec();
}

