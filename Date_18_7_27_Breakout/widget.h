#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QLabel;
class Widget : public QWidget
{
    Q_OBJECT
private:
    void H_Draw();
    void H_DistroyDraw();

    static const int NO_OF_BRICKS=30;
    QLabel *ball;
    QLabel *paddle;
    QLabel *bricks[NO_OF_BRICKS];
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
