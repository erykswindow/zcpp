/********************************************************************************
** Form generated from reading UI file 'pewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PEWINDOW_H
#define UI_PEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PEWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PEWindow)
    {
        if (PEWindow->objectName().isEmpty())
            PEWindow->setObjectName(QStringLiteral("PEWindow"));
        PEWindow->resize(513, 336);
        centralWidget = new QWidget(PEWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        PEWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PEWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 513, 22));
        PEWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PEWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PEWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PEWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PEWindow->setStatusBar(statusBar);

        retranslateUi(PEWindow);

        QMetaObject::connectSlotsByName(PEWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PEWindow)
    {
        PEWindow->setWindowTitle(QApplication::translate("PEWindow", "PEWindow", nullptr));
        pushButton->setText(QApplication::translate("PEWindow", "Open Second", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PEWindow: public Ui_PEWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PEWINDOW_H
