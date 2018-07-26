#ifndef QTEDITER_H
#define QTEDITER_H

#include <QMainWindow>
#include <QTextEdit>
class QAction;
class QLabel;
class QMdiArea;
class QDir;
class QListWidget;
class QLineEdit;
class QtEditer : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtEditer(QWidget *parent = 0);
    ~QtEditer();
public slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveAsFile();
    void alignCenter();
    void undo();
    void redo();
    void copy();
    void cut();
    void paste();
    void zoomIn();
    void zoomOut();
    void help();
    void setColor();
    void setFont();
    void print();
private:
    void H_EditText();
    void H_QMenuBar();
    void H_QToolBar();
    void H_QStatusBar();
    void H_QDockWidget();
    void H_QMdiArea();
    //void H_QMessageBox();
    QAction* makeAction(QString icon,QString name,QString shortCut, QString toolTip, QObject* recv, const char* slot);

    QStatusBar * statusbar;
    QLabel* statusLabel;
    //QTextEdit* textedit;
    QMenuBar* menubar;
    QMdiArea* mdiArea;
};

#endif // QTEDITER_H
