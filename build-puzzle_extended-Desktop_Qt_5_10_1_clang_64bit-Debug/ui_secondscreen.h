/********************************************************************************
** Form generated from reading UI file 'secondscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDSCREEN_H
#define UI_SECONDSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondScreen
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *SecondScreen)
    {
        if (SecondScreen->objectName().isEmpty())
            SecondScreen->setObjectName(QStringLiteral("SecondScreen"));
        SecondScreen->resize(400, 300);
        gridLayout = new QGridLayout(SecondScreen);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(SecondScreen);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(SecondScreen);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(SecondScreen);

        QMetaObject::connectSlotsByName(SecondScreen);
    } // setupUi

    void retranslateUi(QWidget *SecondScreen)
    {
        SecondScreen->setWindowTitle(QApplication::translate("SecondScreen", "Form", nullptr));
        label->setText(QApplication::translate("SecondScreen", "THIS IS THE SECOND SCREEN", nullptr));
        label_2->setText(QApplication::translate("SecondScreen", "Welcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondScreen: public Ui_SecondScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDSCREEN_H
