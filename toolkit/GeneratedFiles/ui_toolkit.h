/********************************************************************************
** Form generated from reading UI file 'toolkit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLKIT_H
#define UI_TOOLKIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_toolkitClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *toolkitClass)
    {
        if (toolkitClass->objectName().isEmpty())
            toolkitClass->setObjectName(QStringLiteral("toolkitClass"));
        toolkitClass->resize(600, 400);
        menuBar = new QMenuBar(toolkitClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        toolkitClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(toolkitClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        toolkitClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(toolkitClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        toolkitClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(toolkitClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        toolkitClass->setStatusBar(statusBar);

        retranslateUi(toolkitClass);

        QMetaObject::connectSlotsByName(toolkitClass);
    } // setupUi

    void retranslateUi(QMainWindow *toolkitClass)
    {
        toolkitClass->setWindowTitle(QApplication::translate("toolkitClass", "toolkit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class toolkitClass: public Ui_toolkitClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLKIT_H
