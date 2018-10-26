/********************************************************************************
** Form generated from reading UI file 'testTreeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTTREEWIDGET_H
#define UI_TESTTREEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testTreeWidgetClass
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QWidget *widget;

    void setupUi(QMainWindow *testTreeWidgetClass)
    {
        if (testTreeWidgetClass->objectName().isEmpty())
            testTreeWidgetClass->setObjectName(QStringLiteral("testTreeWidgetClass"));
        testTreeWidgetClass->resize(600, 400);
        centralWidget = new QWidget(testTreeWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));

        formLayout->setWidget(0, QFormLayout::LabelRole, widget);

        testTreeWidgetClass->setCentralWidget(centralWidget);

        retranslateUi(testTreeWidgetClass);

        QMetaObject::connectSlotsByName(testTreeWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *testTreeWidgetClass)
    {
        testTreeWidgetClass->setWindowTitle(QApplication::translate("testTreeWidgetClass", "testTreeWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testTreeWidgetClass: public Ui_testTreeWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTTREEWIDGET_H
