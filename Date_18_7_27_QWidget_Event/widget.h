#ifndef WIDGET_H
#define WIDGET_H

#include <QLabel>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <QLabel>

class QTimer;
//class Widget : public QLabel
class Widget : public QWidget
{
    Q_OBJECT
    public slots:
        void clockTimer();
    public:
        void H_Timer();
        void H_QObjectTimer();
        Widget(QWidget *parent = 0);
        QLabel *label;
        void H_Thread();
        ~Widget();
    protected:
        void moveEvent(QMoveEvent*);
        void closeEvent(QCloseEvent *event);
        void timerEvent(QTimerEvent *event);
};

#endif // WIDGET_H
