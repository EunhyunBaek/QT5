#include "widget.h"
#include <QApplication>
#include <QLCDNumber>
#include <QProgressBar>
#include <QTextBrowser>
#include <QUrl>
#include <QLineEdit>
void H_QLCDNumber(){

    QLCDNumber *lcd = new QLCDNumber();
    QProgressBar *progBar = new QProgressBar();

    //set progBar
    progBar->setValue(20);
    //set right prog
    //progBar->setInvertedAppearance(true);
    progBar->setRange(0,50);
    progBar->show();

    //set progMode
    lcd->setDecMode();
    //lcd->setBinMode();//over size, so dont setText
    //lcd->setOctMode();
    //lcd->setHexMode();

    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(2002);
    lcd->show();

}

void H_HTMLFunction(){
    QTextBrowser* tb = new QTextBrowser();
    tb->setSource(QUrl("index.html"));
    tb->show();
}

void H_QLineEdit(){
    QLineEdit* lineEdit= new QLineEdit();
    //lineEdit->setEchoMode(QLineEdit::Password);
    lineEdit->setInputMask("099");
    lineEdit->setPlaceholderText("input the number");
    lineEdit->show();
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    H_QLCDNumber();
    H_HTMLFunction();
    H_QLineEdit();
    Widget w;
    w.show();
    return a.exec();
}
