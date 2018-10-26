#ifndef TESTTREEWIDGET_H
#define TESTTREEWIDGET_H
#include <QFileInfoList>
#include <QTextEdit>
#include <QtWidgets/QMainWindow>
#include "ui_testtreewidget.h"
#include "editlabel.h"

class testTreeWidget : public QMainWindow
{
	Q_OBJECT

public:
	testTreeWidget(QWidget *parent = 0);
	~testTreeWidget();
	void creatUi();


private:
	Ui::testTreeWidgetClass ui;
	QAction* CreateAction(QString objectName,QString text);
	bool m_editClicked;
	QList<EditLabel*> m_textEditList;

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

private slots:
	void onTextEditCtrlClicked();
	void onEditTriggered();
	void onSaveTriggered();
	int findListIndex(QPoint point); // 返回鼠标点击了那个文本框
	void setEditEnable(bool enable);
	//void paintEvent(QPaintEvent *event);
};

#endif // TESTTREEWIDGET_H
