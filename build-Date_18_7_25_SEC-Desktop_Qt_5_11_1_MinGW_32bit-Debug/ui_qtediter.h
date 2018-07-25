/********************************************************************************
** Form generated from reading UI file 'qtediter.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEDITER_H
#define UI_QTEDITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtEditer
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtEditer)
    {
        if (QtEditer->objectName().isEmpty())
            QtEditer->setObjectName(QStringLiteral("QtEditer"));
        QtEditer->resize(400, 300);
        menuBar = new QMenuBar(QtEditer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtEditer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtEditer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtEditer->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtEditer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtEditer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtEditer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtEditer->setStatusBar(statusBar);

        retranslateUi(QtEditer);

        QMetaObject::connectSlotsByName(QtEditer);
    } // setupUi

    void retranslateUi(QMainWindow *QtEditer)
    {
        QtEditer->setWindowTitle(QApplication::translate("QtEditer", "QtEditer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtEditer: public Ui_QtEditer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEDITER_H
