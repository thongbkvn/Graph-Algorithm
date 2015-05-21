/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSelect;
    QAction *actionDrawVertex;
    QAction *actionDrawEdge;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 480);
        actionSelect = new QAction(MainWindow);
        actionSelect->setObjectName(QStringLiteral("actionSelect"));
        actionSelect->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/pointer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect->setIcon(icon);
        actionDrawVertex = new QAction(MainWindow);
        actionDrawVertex->setObjectName(QStringLiteral("actionDrawVertex"));
        actionDrawVertex->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/vertex.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDrawVertex->setIcon(icon1);
        actionDrawEdge = new QAction(MainWindow);
        actionDrawEdge->setObjectName(QStringLiteral("actionDrawEdge"));
        actionDrawEdge->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/edge.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDrawEdge->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        toolBar->addAction(actionSelect);
        toolBar->addAction(actionDrawVertex);
        toolBar->addAction(actionDrawEdge);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Graph Algorithm - Pham Van Thong", 0));
        actionSelect->setText(QApplication::translate("MainWindow", "Select", 0));
#ifndef QT_NO_TOOLTIP
        actionSelect->setToolTip(QApplication::translate("MainWindow", "Select", 0));
#endif // QT_NO_TOOLTIP
        actionDrawVertex->setText(QApplication::translate("MainWindow", "Draw Vertex", 0));
#ifndef QT_NO_TOOLTIP
        actionDrawVertex->setToolTip(QApplication::translate("MainWindow", "Draw Vertex", 0));
#endif // QT_NO_TOOLTIP
        actionDrawEdge->setText(QApplication::translate("MainWindow", "Draw Edge", 0));
#ifndef QT_NO_TOOLTIP
        actionDrawEdge->setToolTip(QApplication::translate("MainWindow", "Draw Edge", 0));
#endif // QT_NO_TOOLTIP
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
