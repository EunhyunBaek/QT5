#include "widget.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QLabel* hello=new QLabel("<font color = blue>"
                             "Hello<i>Qt!</i></font>",this);
    QPushButton* quit=new QPushButton("Quit",this);
    quit->resize(75,35);
    hello->resize(100,100);
    quit->move(20,20);
    hello->setGeometry(10,10,30,30);

    //connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
     connect(quit,SIGNAL(clicked()),this,SLOT(slotQuit()));
}
void Widget::slotQuit(){
    qDebug("slotQuit");
    qApp->quit();
}
Widget::~Widget()
{

}

