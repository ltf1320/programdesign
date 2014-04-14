#ifndef FINDFILEFORM_H
#define FINDFILEFORM_H

#include "ui_findfileform.h"

class CFindFileForm:public QWidget
{
    Q_OBJECT
public:
    CFindFileForm(QWidget* =0);
private:
    Ui_FindFileForm ui;
};


#endif // FINDFILEFORM_H
