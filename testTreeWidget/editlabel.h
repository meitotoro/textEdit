#ifndef EDITLABEL_H
#define EDITLABEL_H

#include <QWidget>
#include <QTextEdit>

class EditLabel : public QWidget
{
	Q_OBJECT

public:
	EditLabel(QWidget *parent);
	~EditLabel();
public:
	QTextEdit* m_textEdit;

};

#endif // EDITLABEL_H
