/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <chessview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_Chessboard;
    QAction *actionSave_Chessboard;
    ChessView *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFILE;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 800);
        MainWindow->setMinimumSize(QSize(800, 800));
        actionLoad_Chessboard = new QAction(MainWindow);
        actionLoad_Chessboard->setObjectName(QString::fromUtf8("actionLoad_Chessboard"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Chessboard->setIcon(icon);
        actionSave_Chessboard = new QAction(MainWindow);
        actionSave_Chessboard->setObjectName(QString::fromUtf8("actionSave_Chessboard"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Chessboard->setIcon(icon1);
        centralwidget = new ChessView(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFILE = new QMenu(menubar);
        menuFILE->setObjectName(QString::fromUtf8("menuFILE"));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFILE->menuAction());
        menuFILE->addAction(actionLoad_Chessboard);
        menuFILE->addAction(actionSave_Chessboard);
        toolBar->addAction(actionLoad_Chessboard);
        toolBar->addAction(actionSave_Chessboard);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Chess", nullptr));
        actionLoad_Chessboard->setText(QCoreApplication::translate("MainWindow", "Load Chessboard", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad_Chessboard->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_Chessboard->setText(QCoreApplication::translate("MainWindow", "Save Chessboard", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_Chessboard->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFILE->setTitle(QCoreApplication::translate("MainWindow", "FILE", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
