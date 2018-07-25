#ifndef QTEDITER_H
#define QTEDITER_H

#include <QMainWindow>
#include <QTextEdit>
class QAction;
class QLabel;
namespace Ui {
class QtEditer;
}

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
private:
    Ui::QtEditer *ui;
    void H_EditText();
    void H_QMenuBar();
    void H_QToolBar();
    void H_QStatusBar();
    QAction* makeAction(QString icon,QString name,QString shortCut, QString toolTip, QObject* recv, const char* slot);
    QStatusBar * statusbar;
    QLabel* statusLabel;
    QTextEdit* textedit;
};

#endif // QTEDITER_H
