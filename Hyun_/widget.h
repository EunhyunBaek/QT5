#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton* pushButton[16];
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
