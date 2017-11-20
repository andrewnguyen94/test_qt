#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "view_3d_window.h"

#include <qtextedit.h>

class TextEdit : public QTextEdit
{
public:
    explicit TextEdit(QWidget *widget = nullptr);
    ~TextEdit();

public slots:
    void setText(QString string);
};

#endif // TEXTEDIT_H
