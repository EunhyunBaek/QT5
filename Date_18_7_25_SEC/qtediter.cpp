#include "qtediter.h"
#include "ui_qtediter.h"
#include <QMenuBar>
#include <QApplication>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
QtEditer::QtEditer(QWidget *parent) : QMainWindow(parent)
{
    H_EditText();
    H_QMenuBar();
    H_QToolBar();
    H_QStatusBar();
}

QtEditer::~QtEditer()
{

}
void QtEditer::H_QMenuBar(){
    QMenuBar* menubar = new QMenuBar(this);
    setMenuBar(menubar);

    QAction *newAct=makeAction("new.png","&New","Ctrl+N","make new file",this,SLOT(newFile()));
    //connect(newAct,SIGNAL(triggered()),SLOT(newFile()));
    QAction *quitAct=makeAction("new.png","&Quit","Ctrl+Q","Quit this program",qApp,SLOT(quit()));
    QAction *openAct=makeAction("new.png","O&pen...","Ctrl+P","Open other program",this,SLOT(openFile()));
    QAction *saveAct=makeAction("new.png","&Save","Ctrl+S","Save this program",this,SLOT(saveFile()));
    QAction *saveAsAct=makeAction("new.png","Save &As...","Ctrl+A","Save As this program",this,SLOT(saveAsFile()));
    /*
    fileMenu->addAction("Foint&");
    QAction *newAct=new QAction(QIcon("new.png"),"&New",this);
    QAction *newAct=new QAction(this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("make new file"));
    connect(newAct,SIGNAL(triggered()),SLOT(newFile()));
    */
    QMenu* fileMenu = menubar->addMenu("&File");
    fileMenu->addSeparator();
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addAction(quitAct);

    QMenu* EditMenu = menubar->addMenu("&Edit");
    QAction *undoAct=makeAction("new.png","&Undo","Ctrl+Z","Undo",textedit,SLOT(undo()));
    QAction *redoAct=makeAction("new.png","&Redo","Ctrl+R","Undo",textedit,SLOT(redo()));
    QAction *copyAct=makeAction("new.png","&Copy","Ctrl+C","Undo",textedit,SLOT(copy()));
    QAction *cutAct=makeAction("new.png","Cu&t","Ctrl+T","Undo",textedit,SLOT(cut()));
    QAction *pasteoAct=makeAction("new.png","&Paste","Ctrl+P","Undo",textedit,SLOT(paste()));
    QAction *zoominAct=makeAction("new.png","Zoom &In","Ctrl+I","Undo",textedit,SLOT(zoomIn()));
    QAction *zoomoutAct=makeAction("new.png","Zoom &Out","Ctrl+O","Undo",textedit,SLOT(zoomOut()));

    EditMenu->addAction(undoAct);
    EditMenu->addAction(redoAct);
    EditMenu->addAction(copyAct);
    EditMenu->addAction(cutAct);
    EditMenu->addAction(pasteoAct);
    EditMenu->addAction(zoominAct);
    EditMenu->addAction(zoomoutAct);

    QMenu* HelpMenu = menubar->addMenu("&Help");

}
void QtEditer::H_EditText(){

    textedit = new QTextEdit(this);
    textedit->undo();
    setCentralWidget(textedit);

}
void QtEditer::newFile(){
    qDebug("Make New File");
}
void QtEditer::openFile(){
    qDebug("Open Other File");
}
void QtEditer::saveFile(){
    qDebug("Save This File");
}
void QtEditer::saveAsFile(){
    qDebug("Save As This File");
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
