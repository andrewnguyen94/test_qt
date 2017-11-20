#include "textedit.h"

TextEdit::TextEdit(QWidget *parent) :
    QTextEdit(parent)
{

}

TextEdit::~TextEdit(){

}

void TextEdit::setText(QString string)
{
    QTextEdit::setText(string);
}
