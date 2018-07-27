#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRadioButton>
#include <QButtonGroup>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QStackedLayout>
#include <QDial>
#include <QLabel>
#include <QCalendarWidget>

class QRadioButton;
class QButtonGroup;
class Widget : public QWidget
{
    Q_OBJECT
private:
    QRadioButton* radioButton[4];
    QCheckBox* checkBox[4];
    QButtonGroup* buttonGroup;

    void H_ProgressBar();
    void H_CheckBox();
    void H_QHBoxLayout();
    void H_StackedLayout();
public slots:
    void selectButton(int id);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
