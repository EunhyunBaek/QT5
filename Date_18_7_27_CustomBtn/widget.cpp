#include "widget.h"

#include<QPainter>
Widget::Widget(QWidget *parent):QWidget(parent),m_isEntered(false),m_isHighlighted(false)
{
    resize(130,30);
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent*){
    QPainter painter;
    painter.begin(this);
    painter.setBrush(m_isHighlighted?(Qt::yellow):(m_isEntered?(Qt::darkYellow):(Qt::lightGray)));
    painter.drawRoundedRect(this->rect(),15,15);
    painter.drawText(10,20,QString("x:%1/y:%2").arg(x()).arg(y()));
    painter.end();

    if(m_isHighlighted){
        m_timer.stop();
        m_timer.singleShot(300,this,SLOT(update()));
    }
    m_isHighlighted=false;
}

void Widget::enterEvent(QEvent*){
    m_isEntered=true;
    m_isHighlighted=false;
    update();
}

void Widget::leaveEvent(QEvent*){
    m_isEntered=false;
    m_isHighlighted=false;
    repaint();
}
void Widget::mousePressEvent(QMouseEvent*){
    //m_isEntered=false;
    m_isHighlighted=true;
    update();
    emit clicked();
}
