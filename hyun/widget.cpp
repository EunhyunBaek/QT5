#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    H_Init();
    H_Show();
}

void Widget::H_Init(){
    H_Set_Label();
    H_Set_Btn();
}

void Widget::H_Set_Label(){
    label=new QLabel("0",this);
    label->setAlignment(Qt::AlignRight);
    label->setFrameShape(QFrame::Box);
}

void Widget::H_Set_Btn(){
    const char ButtonChar[16][2]={
        "7","8","9","C",
        "4","5","6","/",
        "1","2","3","X",
        "0","=","+","-"
    };

    gridLayout = new QGridLayout();
    for(int i =0;i<16;i++){
        //for(int j =1;j<5;j++)
          //  printf("%d",i*j);
            pushButton[i]=new QPushButton(ButtonChar[i],this);
            gridLayout->addWidget(pushButton[i],i/4,i%4);
    };

    for(int i = 0;i<=15;i++){
        switch (i) {
        case 3:
            connect(pushButton[i],SIGNAL(clicked()),SLOT(clear()));
            break;
        case 7:
        case 11:
        case 14:
        case 15:
            connect(pushButton[i],SIGNAL(clicked()),SLOT(operation()));
            break;
        case 13:
            connect(pushButton[i],SIGNAL(clicked()),SLOT(calculate()));
            break;
        default:
            connect(pushButton[i],SIGNAL(clicked()),SLOT(setNum()));
            break;
        }
    }
}

void Widget::H_Show(){
    vBoxLayout= new QVBoxLayout(this);
    vBoxLayout->setMargin(0);
    vBoxLayout->addWidget(label);
    vBoxLayout->addLayout(gridLayout);
    setLayout(vBoxLayout);
}

Widget::~Widget()
{
    delete label;
}

void Widget::setNum(){
#if 1
    QString result = (label->text()=="0")?
                ((QPushButton*)sender())->text()
              :label->text()+((QPushButton*)sender())->text();
    label->setText(result);
#else
    label->setText(QString::number(label->text().toFloat()*10+\
                                   ((QPushButton*)sender())->text().toFloat()));
#endif
}

void Widget::operation(){
    numberTemp=label->text();
    operate=((QPushButton*)sender())->text();
    label->setText("0");
}

void Widget::calculate(){
    float result;
    switch(operate.at(0).toLatin1()){
    case '+':result=numberTemp.toFloat()+label->text().toFloat();break;
    case '-':result=numberTemp.toFloat()-label->text().toFloat();break;
    case 'x':result=numberTemp.toFloat()*label->text().toFloat();break;
    case '/':
        if(label->text().toFloat()){
            result=numberTemp.toFloat()/label->text().toFloat();
        }
        else{
            label->setText("Error:Cannot Divide by Zero");
            result = 0;
        }
        break;
    }
    label->setText(QString::number(result));
}

void Widget::clear(){
    numberTemp.setNum(0);
    label->setText("0");
}
