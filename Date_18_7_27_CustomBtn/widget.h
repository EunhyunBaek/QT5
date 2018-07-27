#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
class Widget : public QWidget
{
    Q_OBJECT

public:
    //CustomButton(QWidget * parent=0);
    Widget(QWidget *parent = 0);
    ~Widget();
private:
    bool m_isEntered;
    bool m_isHighlighted;
    QTimer m_timer;
protected:
    void paintEvent(QPaintEvent*);
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
    void mousePressEvent(QMouseEvent*);
signals:
    void clicked();
};

#endif // WIDGET_H
