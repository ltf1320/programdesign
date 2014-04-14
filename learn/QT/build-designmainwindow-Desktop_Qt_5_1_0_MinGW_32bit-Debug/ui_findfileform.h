/********************************************************************************
** Form generated from reading UI file 'findfileform.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFILEFORM_H
#define UI_FINDFILEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FindFileForm
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *nameComboBox;
    QLabel *label_2;
    QLineEdit *txtLineEdit;
    QLabel *label_3;
    QComboBox *dirComboBox;
    QPushButton *browsePushBtn;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *sensitiveCheckBox;
    QCheckBox *subfolderCheckBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *findPushBtn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *stopPushBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *closePushBtn;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLabel *resultLabel;
    QPushButton *openBtn;
    QTableWidget *resultTableWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *statusLabel;
    QLabel *pathLabel;

    void setupUi(QWidget *FindFileForm)
    {
        if (FindFileForm->objectName().isEmpty())
            FindFileForm->setObjectName(QStringLiteral("FindFileForm"));
        FindFileForm->resize(563, 558);
        QIcon icon;
        icon.addFile(QStringLiteral(":/bool.png"), QSize(), QIcon::Normal, QIcon::Off);
        FindFileForm->setWindowIcon(icon);
        FindFileForm->setWindowOpacity(0.3);
        verticalLayout = new QVBoxLayout(FindFileForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(FindFileForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameComboBox = new QComboBox(frame);
        nameComboBox->setObjectName(QStringLiteral("nameComboBox"));
        nameComboBox->setEditable(true);

        gridLayout->addWidget(nameComboBox, 0, 1, 1, 2);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        txtLineEdit = new QLineEdit(frame);
        txtLineEdit->setObjectName(QStringLiteral("txtLineEdit"));

        gridLayout->addWidget(txtLineEdit, 1, 1, 1, 2);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        dirComboBox = new QComboBox(frame);
        dirComboBox->setObjectName(QStringLiteral("dirComboBox"));
        dirComboBox->setEditable(true);

        gridLayout->addWidget(dirComboBox, 2, 1, 1, 1);

        browsePushBtn = new QPushButton(frame);
        browsePushBtn->setObjectName(QStringLiteral("browsePushBtn"));

        gridLayout->addWidget(browsePushBtn, 2, 2, 1, 1);

        label->raise();
        label_2->raise();
        label_3->raise();
        nameComboBox->raise();
        txtLineEdit->raise();
        dirComboBox->raise();
        browsePushBtn->raise();

        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sensitiveCheckBox = new QCheckBox(FindFileForm);
        sensitiveCheckBox->setObjectName(QStringLiteral("sensitiveCheckBox"));

        horizontalLayout->addWidget(sensitiveCheckBox);

        subfolderCheckBox = new QCheckBox(FindFileForm);
        subfolderCheckBox->setObjectName(QStringLiteral("subfolderCheckBox"));

        horizontalLayout->addWidget(subfolderCheckBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        findPushBtn = new QPushButton(FindFileForm);
        findPushBtn->setObjectName(QStringLiteral("findPushBtn"));

        horizontalLayout_2->addWidget(findPushBtn);

        horizontalSpacer_4 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        stopPushBtn = new QPushButton(FindFileForm);
        stopPushBtn->setObjectName(QStringLiteral("stopPushBtn"));

        horizontalLayout_2->addWidget(stopPushBtn);

        horizontalSpacer_5 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        closePushBtn = new QPushButton(FindFileForm);
        closePushBtn->setObjectName(QStringLiteral("closePushBtn"));

        horizontalLayout_2->addWidget(closePushBtn);

        horizontalSpacer_6 = new QSpacerItem(29, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(FindFileForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        resultLabel = new QLabel(FindFileForm);
        resultLabel->setObjectName(QStringLiteral("resultLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(resultLabel->sizePolicy().hasHeightForWidth());
        resultLabel->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(resultLabel);

        openBtn = new QPushButton(FindFileForm);
        openBtn->setObjectName(QStringLiteral("openBtn"));

        horizontalLayout_4->addWidget(openBtn);


        verticalLayout->addLayout(horizontalLayout_4);

        resultTableWidget = new QTableWidget(FindFileForm);
        if (resultTableWidget->columnCount() < 5)
            resultTableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        resultTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        resultTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        resultTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        resultTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        resultTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        resultTableWidget->setObjectName(QStringLiteral("resultTableWidget"));

        verticalLayout->addWidget(resultTableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        statusLabel = new QLabel(FindFileForm);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(statusLabel->sizePolicy().hasHeightForWidth());
        statusLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(statusLabel);

        pathLabel = new QLabel(FindFileForm);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));
        pathLabel->setTextFormat(Qt::AutoText);
        pathLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(pathLabel);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(FindFileForm);

        QMetaObject::connectSlotsByName(FindFileForm);
    } // setupUi

    void retranslateUi(QWidget *FindFileForm)
    {
        FindFileForm->setWindowTitle(QApplication::translate("FindFileForm", "\346\237\245\346\211\276\346\226\207\344\273\266", 0));
        label->setText(QApplication::translate("FindFileForm", "\345\220\215\344\270\272", 0));
        label_2->setText(QApplication::translate("FindFileForm", "\345\214\205\345\220\253\346\226\207\346\234\254", 0));
        label_3->setText(QApplication::translate("FindFileForm", "\346\237\245\346\211\276\344\275\215\347\275\256", 0));
        browsePushBtn->setText(QApplication::translate("FindFileForm", "\346\265\217\350\247\210..", 0));
        sensitiveCheckBox->setText(QApplication::translate("FindFileForm", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", 0));
        subfolderCheckBox->setText(QApplication::translate("FindFileForm", "\345\214\205\345\220\253\345\255\220\346\226\207\344\273\266\345\244\271", 0));
        findPushBtn->setText(QApplication::translate("FindFileForm", "\346\237\245\346\211\276", 0));
        stopPushBtn->setText(QApplication::translate("FindFileForm", "\345\201\234\346\255\242", 0));
        closePushBtn->setText(QApplication::translate("FindFileForm", "\345\205\263\351\227\255", 0));
        label_4->setText(QApplication::translate("FindFileForm", "\346\237\245\346\211\276\347\273\223\346\236\234", 0));
        resultLabel->setText(QApplication::translate("FindFileForm", "\346\211\276\345\210\2600\344\270\252\346\226\207\344\273\266", 0));
        openBtn->setText(QApplication::translate("FindFileForm", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        QTableWidgetItem *___qtablewidgetitem = resultTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FindFileForm", "\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = resultTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FindFileForm", "\345\244\247\345\260\217", 0));
        QTableWidgetItem *___qtablewidgetitem2 = resultTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FindFileForm", "\344\277\256\346\224\271\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem3 = resultTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FindFileForm", "\346\235\203\351\231\220", 0));
        QTableWidgetItem *___qtablewidgetitem4 = resultTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("FindFileForm", "\344\275\215\347\275\256", 0));
        statusLabel->setText(QApplication::translate("FindFileForm", "\347\212\266\346\200\201", 0));
        pathLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FindFileForm: public Ui_FindFileForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFILEFORM_H
