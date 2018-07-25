#include "widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    const char ButtonChar[16][2]={
        "7","8","9","C",
        "4","5","6","/",
        "1","2","3","X",
        "0","=","+","-"
    };
    for(int i =0;i<5;i++){
        pushButton[i]=new QPushButton(ButtonChar[i],this);
    }

}

Widget::~Widget()
{

}
