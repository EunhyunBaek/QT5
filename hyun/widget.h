#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QPushButton>
#include<QLabel>

class QLabel;
class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel* label;
    QString numberTemp;
    QString operate;
    QPushButton* pushButton[16];
    QGridLayout* gridLayout;
    QVBoxLayout* vBoxLayout;
public:
    void H_Set_Label();
    void H_Set_Btn();
    void H_Init();
    void H_Show();
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void setNum();
    void operation();
    void calculate();
    void clear();
};

#endif // WIDGET_H
