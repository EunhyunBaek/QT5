#include "qtediter.h"
#include <QMenuBar>
#include <QApplication>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>
#include <QPrinter>
#include <QPrintDialog>
QtEditer::QtEditer(QWidget *parent) : QMainWindow(parent)
{
    H_QMdiArea();
    H_EditText();
    H_QMenuBar();
    H_QToolBar();
    H_QStatusBar();
}

QtEditer::~QtEditer()
{

}
void QtEditer::H_QMenuBar(){
    menubar = new QMenuBar(this);
    setMenuBar(menubar);
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QAction *newAct=makeAction("new.png","&New","Ctrl+N","make new file",this,SLOT(newFile()));
    //connect(newAct,SIGNAL(triggered()),SLOT(newFile()));
    QAction *quitAct=makeAction("new.png","&Quit","Ctrl+Q","Quit this program",qApp,SLOT(quit()));
    QAction *openAct=makeAction("new.png","O&pen...","Ctrl+P","Open other program",this,SLOT(openFile()));
    QAction *saveAct=makeAction("new.png","&Save","Ctrl+S","Save this program",this,SLOT(saveFile()));
    QAction *saveAsAct=makeAction("new.png","Save &As...","Ctrl+A","Save As this program",this,SLOT(saveAsFile()));

    QMenu* fileMenu = menubar->addMenu("&File");
    fileMenu->addSeparator();
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(quitAct);

    QMenu* EditMenu = menubar->addMenu("&Edit");
    QAction *undoAct=makeAction("new.png","&Undo","Ctrl+Z","Undo",this,SLOT(undo()));
    QAction *redoAct=makeAction("new.png","&Redo","Ctrl+R","Undo",this,SLOT(redo()));
    QAction *copyAct=makeAction("new.png","&Copy","Ctrl+C","Undo",this,SLOT(copy()));
    QAction *cutAct=makeAction(":/images/cut.png","Cu&t","Ctrl+T","Undo",this,SLOT(cut()));
    QAction *pasteoAct=makeAction("new.png","&Paste","Ctrl+P","Undo",this,SLOT(paste()));
    QAction *zoominAct=makeAction("new.png","Zoom &In","Ctrl+I","Undo",this,SLOT(zoomIn()));
    QAction *zoomoutAct=makeAction(":/images/camara.png","Zoom &Out","Ctrl+O","Undo",this,SLOT(zoomOut()));

    //disconnect()

    EditMenu->addAction(undoAct);
    EditMenu->addAction(redoAct);
    EditMenu->addAction(copyAct);
    EditMenu->addAction(cutAct);
    EditMenu->addAction(pasteoAct);
    EditMenu->addAction(zoominAct);
    EditMenu->addAction(zoomoutAct);

    QMenu* alignMenu= EditMenu->addMenu("&Align");
    QAction* alignCenterAct = new QAction("&Center",this);
    connect(alignCenterAct,SIGNAL(triggered()),this,SLOT(alignCenter()));
    alignMenu->addAction(alignCenterAct);

     QMenu* HelpMenu = menubar->addMenu("&Help");
     QAction *helpAct=makeAction(":/images/camara.png","&Help","Ctrl+O","Undo",this,SLOT(help()));
     //QAction *aboutAct=makeAction(":/images/camara.png","&Helpabout","Ctrl+O","Undo",this,SLOT(aboutQt()));
     HelpMenu->addAction(helpAct);

     QMenu* Format = menubar->addMenu("&Format");
     QAction* setColorAct=makeAction(":/images/camara.png","&Color","Ctrl+O","Undo",this,SLOT(setColor()));
     QAction* setFontAct=makeAction(":/images/camara.png","&Font","Ctrl+O","Undo",this,SLOT(setFont()));
     QAction* printAct=makeAction(":/images/camara.png","&Print","Ctrl+O","Undo",this,SLOT(print()));
     Format->addAction(setColorAct);
     Format->addAction(setFontAct);
     Format->addAction(printAct);
     //HelpMenu->addAction(aboutAct);
}
void QtEditer::H_EditText(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //textedit->undo();
//    setCentralWidget(textedit);

}
void QtEditer::newFile(){
    QTextEdit* textedit = new QTextEdit();
    mdiArea->addSubWindow(textedit);
    //connect(mdiArea,SIGNAL(triggered()),textedit,SLOT(activateNextSubWindow()));
    textedit->show();
    qDebug("Make New File");


}
void QtEditer::openFile(){
    qDebug("Open Other File");
    QString filename=QFileDialog::getOpenFileName(this,"Select file to Open",".","Text File(*.text *.txt *.html *.c *.cpp *.h)");
    qDebug()<<filename;
    QFileInfo* fileinfo=new QFileInfo(filename);
    if(fileinfo->isReadable()){
        QByteArray msg;
        QFile* file = new QFile(filename);
        file->open(QIODevice::ReadOnly);
        msg=file->readAll();
        file->close();
        delete file;
        QTextEdit* textedit = new QTextEdit(this);
        textedit -> setWindowTitle(filename);
        textedit->setHtml(msg);
        mdiArea->addSubWindow(textedit);
        textedit->show();
    }
    else{
        QMessageBox::warning(this,"Error","Can't Read this file",QMessageBox::Ok,NULL);
    }
}
/*
void QtEditer::saveFile(){
    qDebug("Save This File");
    QString filename=QFileDialog::getSaveFileName(this,"Select file to Save",".","Text File(*.txt *.html *.c *.cpp *.h)");
    qDebug()<<filename;
}
*/
void QtEditer::saveFile(){
    qDebug("save File");
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QString filename = textedit->windowTitle();
    if(!filename.length()){
        filename=QFileDialog::getSaveFileName(this,"Select a file to save",".","Text File(*.text *.txt *.html *.htm *.c *.cpp *.h)");
        textedit->setWindowTitle(filename);
    }
    QFile* file=new QFile(filename);
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QFileInfo* fileinfo = new QFileInfo(filename);
    if(fileinfo->isWritable()){
        QByteArray msg;
        msg.append(textedit->toHtml());
        file->write(msg);
    }
    else{
        QMessageBox::warning(this,"Error","can't Save thisfile.",QMessageBox::Ok,NULL);
    }
    file->close();
    delete file;
}
void QtEditer::saveAsFile(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    qDebug("Save As This File");
    QString filename=QFileDialog::getSaveFileName(this,"Select file to Save",".","Text File(*.text *.txt *.html *.c *.cpp *.h)");
    qDebug()<<filename;
    textedit->setWindowTitle(filename);
    QFile* file=new QFile(filename);
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QFileInfo* fileinfo = new QFileInfo(filename);
    if(fileinfo->isWritable()){
        QByteArray msg;
        msg.append(textedit->toHtml());
        file->write(msg);
    }
    else{
        QMessageBox::warning(this,"Error","can't Save thisfile.",QMessageBox::Ok,NULL);
    }
    file->close();
    delete file;
}

QAction *QtEditer::makeAction(QString icon, QString name, QString shortCut, QString toolTip, QObject *recv, const char *slot){
    QAction *act=new QAction(name,this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    connect(act,SIGNAL(triggered()),recv,slot);
    return act;
}
void QtEditer::H_QToolBar(){
    QAction *newAct=makeAction("new.png","&New","Ctrl+N","make new file",this,SLOT(newFile()));
    QAction *quitAct=makeAction("new.png","&Quit","Ctrl+Q","Quit this program",qApp,SLOT(quit()));
    QToolBar *fileToolBar = addToolBar("&File");
    fileToolBar->addSeparator();
    //fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    fileToolBar->addAction(newAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);
}

void QtEditer::H_QStatusBar(){
    statusbar = statusBar();
    statusLabel = new QLabel("Qt Editor",statusbar);
    statusbar ->addPermanentWidget(statusLabel);
    statusbar ->showMessage("started",1500);
}

void QtEditer::alignCenter(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //QAction *action =(QAction*)sender();
    textedit->setAlignment(Qt::AlignCenter);
}

void QtEditer::undo(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //QAction *action =(QAction*)sender();
    textedit->undo();
}
void QtEditer::redo(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //QAction *action =(QAction*)sender();
    textedit->redo();
}
void QtEditer::copy(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //QAction *action =(QAction*)sender();
    textedit->copy();
}
void QtEditer::cut(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //QAction *action =(QAction*)sender();
    textedit->cut();
}
void QtEditer::paste(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //QAction *action =(QAction*)sender();
    textedit->paste();
}
void QtEditer::zoomIn(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //QAction *action =(QAction*)sender();
    textedit->zoomIn();
}
void QtEditer::zoomOut(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    //QAction *action =(QAction*)sender();
    textedit->zoomOut();
}
void QtEditer::H_QDockWidget(){
    QLabel*label = new QLabel("Dock Widget",this);
    QDockWidget *dock=new QDockWidget("Dock Widget",this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    dock->setWidget(label);
    menubar->addAction(dock->toggleViewAction());
}

void QtEditer::H_QMdiArea(){
    mdiArea=new QMdiArea(this);
    setCentralWidget(mdiArea);
    mdiArea->tileSubWindows();
#if 0
    QTextEdit* textedit = new QTextEdit(this);
    mdiArea->addSubWindow(textedit);
#else
    newFile();
#endif
}
/*
void QtEditer::H_QMessageBox(){
    QMessageBox::Question(this,"QMessageBox::showQuestion()","Question Message",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
}
*/
void QtEditer::help(){
    QMessageBox* msgBox = new QMessageBox();
    msgBox->question(this,"QMessageBox::showQuestion()","Question Message",QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
    msgBox->aboutQt(this,"about");
    //QAction *action =(QAction*)sender();
    //textedit->aboutQt();
}

void QtEditer::setColor(){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QColor color = QColorDialog::getColor(textedit->textColor(),this);
    textedit->setTextColor(color);
}

void QtEditer::setFont(){
    bool ok;
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QFont font = QFontDialog::getFont(&ok,textedit->currentFont(),this);
    if(ok) textedit->setCurrentFont(font);
}

void QtEditer::print(){
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(true);
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec() == QDialog::Accepted){
    QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    textedit->print(&printer);
    }
}
