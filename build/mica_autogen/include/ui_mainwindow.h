/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ButtonControl.h"
#include "CardControl.h"
#include "ComboBoxControl.h"
#include "Control.h"
#include "TextBlockControl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    TextBlockControl *textBlock;
    QVBoxLayout *vboxLayout;
    ButtonControl *button;
    QVBoxLayout *_2;
    CardControl *widget;
    QHBoxLayout *horizontalLayout_3;
    ButtonControl *bourt;
    QSpacerItem *horizontalSpacer_2;
    ComboBoxControl *button_4;
    QVBoxLayout *_4;
    ButtonControl *button_3;
    QVBoxLayout *_3;
    TextBlockControl *icon;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    Control *widget_2;
    QSpacerItem *horizontalSpacer_3;
    ButtonControl *button_5;
    QVBoxLayout *_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 360);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textBlock = new TextBlockControl(centralwidget);
        textBlock->setObjectName(QString::fromUtf8("textBlock"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBlock->sizePolicy().hasHeightForWidth());
        textBlock->setSizePolicy(sizePolicy);
        vboxLayout = new QVBoxLayout(textBlock);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(textBlock);

        button = new ButtonControl(centralwidget);
        button->setObjectName(QString::fromUtf8("button"));
        sizePolicy.setHeightForWidth(button->sizePolicy().hasHeightForWidth());
        button->setSizePolicy(sizePolicy);
        _2 = new QVBoxLayout(button);
        _2->setObjectName(QString::fromUtf8("_2"));
        _2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(button);


        verticalLayout->addLayout(horizontalLayout);

        widget = new CardControl(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        bourt = new ButtonControl(widget);
        bourt->setObjectName(QString::fromUtf8("bourt"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bourt->sizePolicy().hasHeightForWidth());
        bourt->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(bourt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        button_4 = new ComboBoxControl(widget);
        button_4->setObjectName(QString::fromUtf8("button_4"));
        sizePolicy.setHeightForWidth(button_4->sizePolicy().hasHeightForWidth());
        button_4->setSizePolicy(sizePolicy);
        _4 = new QVBoxLayout(button_4);
        _4->setObjectName(QString::fromUtf8("_4"));
        _4->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_3->addWidget(button_4);

        button_3 = new ButtonControl(widget);
        button_3->setObjectName(QString::fromUtf8("button_3"));
        sizePolicy.setHeightForWidth(button_3->sizePolicy().hasHeightForWidth());
        button_3->setSizePolicy(sizePolicy);
        _3 = new QVBoxLayout(button_3);
        _3->setObjectName(QString::fromUtf8("_3"));
        _3->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_3->addWidget(button_3);

        icon = new TextBlockControl(widget);
        icon->setObjectName(QString::fromUtf8("icon"));

        horizontalLayout_3->addWidget(icon);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widget_2 = new Control(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(widget_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        button_5 = new ButtonControl(centralwidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));
        sizePolicy.setHeightForWidth(button_5->sizePolicy().hasHeightForWidth());
        button_5->setSizePolicy(sizePolicy);
        _5 = new QVBoxLayout(button_5);
        _5->setObjectName(QString::fromUtf8("_5"));
        _5->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(button_5);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
