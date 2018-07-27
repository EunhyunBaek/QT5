#include "widget.h"
#include <QLabel>
#define WIDTH 50
#define HEIGHT 12
#define SCR_WIDTH 300
#define SCR_HEIGHT 400
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    H_Draw();
}

Widget::~Widget()
{
    H_DistroyDraw();
}

void Widget::H_Draw(){
    ball=new QLabel(this);
    ball->setGeometry(SCR_WIDTH*0.8,SCR_HEIGHT*0.875,10,10);
    ball->setStyleSheet("QLabel{background-color:Red;border-radius:5px;}");
    paddle = new QLabel(this);
    paddle->setGeometry(SCR_WIDTH*0.7,SCR_HEIGHT*0.9,WIDTH,HEIGHT);
    paddle->setStyleSheet("QLabel{background-color:blue;}");
    for (int y=0,i=0;y<5;y++)
        for(int x=0; x<6;x++,i++){
            bricks[i] = new QLabel(this);
            bricks[i]->setStyleSheet("QLabel{background-color:cyan;""border:1px solid black}");
            bricks[i]->setGeometry(x*WIDTH,y*HEIGHT+30,WIDTH,HEIGHT);
        }
    resize(SCR_WIDTH,SCR_HEIGHT);
}
void Widget::H_DistroyDraw(){
    delete ball;
    delete paddle;
    for(int i =0;i<NO_OF_BRICKS;i++){
        delete bricks[i];
    }
}
