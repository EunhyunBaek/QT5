#include "widget.h"
#include "thread.h"
#include <QLabel>
#include <QCloseEvent>
#include <QTime>
#include <QTimer>
#include <QtGui>
#include <QtWidgets>

//Widget::Widget(QWidget *parent) : QLabel(parent)
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    //setText("Hello World");
    //resize(100,30);
    //H_Timer();
    //H_QObjectTimer();
    H_Thread();
}

Widget::~Widget()
{
    thread()->terminate();//wait()
}

void Widget::moveEvent(QMoveEvent*){
    //setText(QString("X: %1, Y : %2").arg(pos().x()).arg(pos().y()));
}
void Widget::closeEvent(QCloseEvent* event){
    event->ignore();//event->accept()

}
void Widget::clockTimer(){
    //setText(QTime::currentTime().toString());
}

void Widget::H_Timer(){
    QTimer* timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),SLOT(clockTimer()));
    timer->start(1000*60);
    resize(90,40);
}
void Widget::H_QObjectTimer(){
    label = new QLabel("Timer",this);
    int id1 = startTimer(50);
    int id2 = startTimer(1000);
}

void Widget::timerEvent(QTimerEvent *event){
    label->setText(QString(event->timerId()));
}

void Widget::H_Thread(){
    QLabel* label= new QLabel(this);
    Thread* thread=new Thread(label);

    QPushButton* stopButton= new QPushButton("Stop",this);
    QPushButton* resumeButton = new QPushButton("Resume",this);

    QHBoxLayout* hboxlayout=new QHBoxLayout;
    hboxlayout->addWidget(stopButton);
    hboxlayout->addWidget(resumeButton);
    QVBoxLayout* vboxlayout=new QVBoxLayout(this);
    vboxlayout->addWidget(label);
    vboxlayout->addLayout(hboxlayout);

    connect(stopButton,SIGNAL(clicked()),thread,SLOT(stopThread()));
    connect(resumeButton,SIGNAL(clicked()),thread,SLOT(resumeThread()));
    connect(thread,SIGNAL(setLabel(QString)),label,SLOT(setText(QString)));

    thread->start();
}
