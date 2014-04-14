/********************************************************************************
** Form generated from reading UI file 'editpatr.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPATR_H
#define UI_EDITPATR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editPatr
{
public:
    QTextEdit *textEdit;
    QWidget *editSelectWidget;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *boldPushButton;
    QPushButton *italyPushButton;
    QPushButton *pushButton;
    QWidget *infoContainWidget;
    QLabel *showcreattimeLabel;
    QLabel *showmodifyTimelabel;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *editPatr)
    {
        if (editPatr->objectName().isEmpty())
            editPatr->setObjectName(QStringLiteral("editPatr"));
        editPatr->resize(777, 497);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(editPatr->sizePolicy().hasHeightForWidth());
        editPatr->setSizePolicy(sizePolicy);
        editPatr->setMinimumSize(QSize(0, 0));
        editPatr->setMaximumSize(QSize(167777, 167777));
        textEdit = new QTextEdit(editPatr);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 150, 777, 348));
        editSelectWidget = new QWidget(editPatr);
        editSelectWidget->setObjectName(QStringLiteral("editSelectWidget"));
        editSelectWidget->setGeometry(QRect(0, 96, 777, 54));
        sizePolicy.setHeightForWidth(editSelectWidget->sizePolicy().hasHeightForWidth());
        editSelectWidget->setSizePolicy(sizePolicy);
        editSelectWidget->setMinimumSize(QSize(0, 0));
        editSelectWidget->setMaximumSize(QSize(167777, 16777215));
        editSelectWidget->setStyleSheet(QLatin1String("#editSelectWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        comboBox = new QComboBox(editSelectWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 10, 69, 26));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(0, 26));
        comboBox->setMaximumSize(QSize(16777215, 26));
        comboBox->setEditable(false);
        comboBox_2 = new QComboBox(editSelectWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 10, 41, 26));
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);
        comboBox_2->setMinimumSize(QSize(0, 26));
        comboBox_2->setMaximumSize(QSize(16777215, 26));
        comboBox_2->setEditable(true);
        boldPushButton = new QPushButton(editSelectWidget);
        boldPushButton->setObjectName(QStringLiteral("boldPushButton"));
        boldPushButton->setGeometry(QRect(130, 10, 28, 28));
        boldPushButton->setMinimumSize(QSize(28, 28));
        boldPushButton->setMaximumSize(QSize(28, 28));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        boldPushButton->setFont(font);
        italyPushButton = new QPushButton(editSelectWidget);
        italyPushButton->setObjectName(QStringLiteral("italyPushButton"));
        italyPushButton->setGeometry(QRect(160, 10, 75, 23));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(italyPushButton->sizePolicy().hasHeightForWidth());
        italyPushButton->setSizePolicy(sizePolicy2);
        pushButton = new QPushButton(editSelectWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 10, 75, 23));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        infoContainWidget = new QWidget(editPatr);
        infoContainWidget->setObjectName(QStringLiteral("infoContainWidget"));
        infoContainWidget->setGeometry(QRect(0, 41, 777, 55));
        infoContainWidget->setMaximumSize(QSize(16777215, 55));
        infoContainWidget->setStyleSheet(QLatin1String("#infoContainWidget{\n"
"	background-color: rgb(241, 241, 241);\n"
"}"));
        showcreattimeLabel = new QLabel(infoContainWidget);
        showcreattimeLabel->setObjectName(QStringLiteral("showcreattimeLabel"));
        showcreattimeLabel->setGeometry(QRect(-1, 0, 371, 61));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(showcreattimeLabel->sizePolicy().hasHeightForWidth());
        showcreattimeLabel->setSizePolicy(sizePolicy3);
        showcreattimeLabel->setStyleSheet(QStringLiteral("#showcreattimeLabel{background-color: rgb(255, 98, 7);}"));
        showcreattimeLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        showmodifyTimelabel = new QLabel(infoContainWidget);
        showmodifyTimelabel->setObjectName(QStringLiteral("showmodifyTimelabel"));
        showmodifyTimelabel->setGeometry(QRect(370, 0, 407, 61));
        sizePolicy.setHeightForWidth(showmodifyTimelabel->sizePolicy().hasHeightForWidth());
        showmodifyTimelabel->setSizePolicy(sizePolicy);
        showmodifyTimelabel->setStyleSheet(QLatin1String("#showmodifyTimelabel{\n"
"	background-color: rgb(255, 136, 32);\n"
"}"));
        lineEdit = new QLineEdit(editPatr);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 0, 777, 40));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMinimumSize(QSize(0, 20));
        lineEdit->setMaximumSize(QSize(16767, 40));
        lineEdit->setFocusPolicy(Qt::ClickFocus);
        layoutWidget = new QWidget(editPatr);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget->raise();
        textEdit->raise();
        editSelectWidget->raise();
        infoContainWidget->raise();
        lineEdit->raise();

        retranslateUi(editPatr);

        QMetaObject::connectSlotsByName(editPatr);
    } // setupUi

    void retranslateUi(QWidget *editPatr)
    {
        editPatr->setWindowTitle(QApplication::translate("editPatr", "Form", 0));
        boldPushButton->setText(QApplication::translate("editPatr", "B", 0));
        italyPushButton->setText(QApplication::translate("editPatr", "PushButton", 0));
        pushButton->setText(QApplication::translate("editPatr", "PushButton", 0));
        showcreattimeLabel->setText(QString());
        showmodifyTimelabel->setText(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QApplication::translate("editPatr", "\346\227\240\346\240\207\351\242\230\347\254\224\350\256\260", 0));
    } // retranslateUi

};

namespace Ui {
    class editPatr: public Ui_editPatr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPATR_H
