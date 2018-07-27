#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //H_ProgressBar();
    //H_CheckBox();
    //H_QHBoxLayout();
    H_StackedLayout();
}

Widget::~Widget()
{

}
void Widget::H_ProgressBar(){
    resize(140,110);
    buttonGroup=new QButtonGroup(this);
    for(int i=0;i<4;i++){
        QString str = QString("RadioButton%1").arg(i+1);
        radioButton[i]=new QRadioButton(str,this);
        radioButton[i]->move(10,10+20*i);
        buttonGroup->addButton(radioButton[i]);
    }
}
void Widget::H_CheckBox(){
    resize(140,110);
    buttonGroup=new QButtonGroup(this);
    buttonGroup->setExclusive(false);
    //if 3 args is this, skip this arg
    //connect(buttonGroup,SIGNAL(buttonClicked(int)),SLOT(selectButton(int)));
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(selectButton(int)));
    for(int i=0;i<4;i++){
        QString str = QString("CheckButton%1").arg(i+1);
        checkBox[i]=new QCheckBox(str,this);
        checkBox[i]->move(10,10+20*i);
        buttonGroup->addButton(checkBox[i],i);
    }
}

void Widget::selectButton(int id){
    QButtonGroup* buttonGroup= (QButtonGroup*)sender();
    QCheckBox* button = (QCheckBox*)buttonGroup->button(id);
    qDebug("CheckBox%d is selected(%s)",id+1,(button->isChecked())?"On":"Off");

}

void Widget::H_QHBoxLayout(){
    QPushButton* pushButton1 = new QPushButton();
    pushButton1->setText("Button1");
    QPushButton* pushButton2 = new QPushButton("Button2");
    pushButton2->show();
    QPushButton* pushButton3 = new QPushButton("Button3",this);

    /*
    QHBoxLayout* hBoxLayout= new QHBoxLayout;
    hBoxLayout->setMargin(0);
    hBoxLayout->addWidget(pushButton1);
    hBoxLayout->addWidget(pushButton2);
    hBoxLayout->addWidget(pushButton3);
    setLayout(hBoxLayout);
    */

}

void Widget::H_StackedLayout(){
    QDial* dial= new QDial();
    dial->setRange(0,2);

    QLabel* label = new QLabel("Stack1");
    QCalendarWidget* calendarWidget = new QCalendarWidget();
    QTextEdit* textEdit = new QTextEdit("Stack3");
    QStackedLayout* stackedLayout= new QStackedLayout();
    stackedLayout->addWidget(label);
    stackedLayout->addWidget(calendarWidget);
    stackedLayout->addWidget(textEdit);

    connect(dial,SIGNAL(valueChanged(int)),stackedLayout,SLOT(setCurrentIndex(int)));
    QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
    hBoxLayout->addWidget(dial);
    hBoxLayout->addLayout(stackedLayout);

    setLayout(hBoxLayout);
}
