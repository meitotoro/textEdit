#include "editlabel.h"

EditLabel::EditLabel(QWidget *parent)
{
	this->setParent(parent);
	m_textEdit=new QTextEdit(this);
}

EditLabel::~EditLabel()
{

}
