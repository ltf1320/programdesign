/********************************************************************************
** Form generated from reading UI file 'findWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDWIDGET_H
#define UI_FINDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_findWidget
{
public:
    QPushButton *preBtn;
    QPushButton *nextBtn;
    QLabel *picnoLabel;
    QLabel *difLabel;
    QLabel *label_3;

    void setupUi(QWidget *findWidget)
    {
        if (findWidget->objectName().isEmpty())
            findWidget->setObjectName(QStringLiteral("findWidget"));
        findWidget->resize(400, 300);
        preBtn = new QPushButton(findWidget);
        preBtn->setObjectName(QStringLiteral("preBtn"));
        preBtn->setGeometry(QRect(60, 240, 75, 23));
        nextBtn = new QPushButton(findWidget);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));
        nextBtn->setGeometry(QRect(230, 240, 75, 23));
        picnoLabel = new QLabel(findWidget);
        picnoLabel->setObjectName(QStringLiteral("picnoLabel"));
        picnoLabel->setGeometry(QRect(160, 240, 54, 12));
        difLabel = new QLabel(findWidget);
        difLabel->setObjectName(QStringLiteral("difLabel"));
        difLabel->setGeometry(QRect(180, 270, 54, 12));
        label_3 = new QLabel(findWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 270, 54, 12));

        retranslateUi(findWidget);

        QMetaObject::connectSlotsByName(findWidget);
    } // setupUi

    void retranslateUi(QWidget *findWidget)
    {
        findWidget->setWindowTitle(QApplication::translate("findWidget", "Form", 0));
        preBtn->setText(QApplication::translate("findWidget", "\345\211\215\344\270\200\344\270\252", 0));
        nextBtn->setText(QApplication::translate("findWidget", "\345\220\216\344\270\200\344\270\252", 0));
        picnoLabel->setText(QApplication::translate("findWidget", "TextLabel", 0));
        difLabel->setText(QApplication::translate("findWidget", "0", 0));
        label_3->setText(QApplication::translate("findWidget", "dif:", 0));
    } // retranslateUi

};

namespace Ui {
    class findWidget: public Ui_findWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDWIDGET_H
