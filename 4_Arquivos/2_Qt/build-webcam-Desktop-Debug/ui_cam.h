/********************************************************************************
** Form generated from reading UI file 'cam.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAM_H
#define UI_CAM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cam
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Cam)
    {
        if (Cam->objectName().isEmpty())
            Cam->setObjectName(QString::fromUtf8("Cam"));
        Cam->resize(400, 300);
        menuBar = new QMenuBar(Cam);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Cam->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Cam);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Cam->addToolBar(mainToolBar);
        centralWidget = new QWidget(Cam);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Cam->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Cam);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Cam->setStatusBar(statusBar);

        retranslateUi(Cam);

        QMetaObject::connectSlotsByName(Cam);
    } // setupUi

    void retranslateUi(QMainWindow *Cam)
    {
        Cam->setWindowTitle(QApplication::translate("Cam", "Cam", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Cam: public Ui_Cam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAM_H
