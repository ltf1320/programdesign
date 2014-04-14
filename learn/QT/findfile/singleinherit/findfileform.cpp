#include "findfileform.h"
#include <QDir>

CFindFileForm::CFindFileForm(QWidget* parent):QWidget(parent)
{
    ui.setupUi(this);
    ui.statusLabel->setText(tr("就绪"));
    ui.resultLabel->setText(tr("找到0个文件"));
    ui.nameComboBox->setEditText("*");;
    ui.dirComboBox->setEditText(QDir::currentPath());
    ui.dirComboBox->addItem(QDir::currentPath());
    ui.sensitiveCheckBox->setEnabled(false);
    ui.stopPushBtn->setEnabled(false);
}
