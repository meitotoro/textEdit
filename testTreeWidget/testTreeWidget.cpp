#include "testtreewidget.h"
#include <QTreeWidget>
#include <QMenuBar>
#include <QMouseEvent>
#include <QTextEdit>
#include <QAction>
#include <QTreeWidgetItem>
#include <QPainter>
#include <QPalette>
#include "point.h"
#include "eightpoints.h"

testTreeWidget::testTreeWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	EightPoints::m_parent=this;
	creatUi();
	m_editClicked=false;
	QPalette pal(this->palette());
	pal.setColor(QPalette::Background,Qt::white);
	this->setAutoFillBackground(true);
	this->setPalette(pal);
	//this->resize(500,500);
}

testTreeWidget::~testTreeWidget()
{
	int count=m_textEditList.count();
	if(count>0)
	{
		for (int i=0;i<count;i++)
		{
			EditLabel* textEdit=m_textEditList[i];
			delete textEdit;
		}
	}
}
void testTreeWidget::creatUi()
{

	setWindowTitle(QString::fromLocal8Bit("文本编辑器(左屏)"));
	QMenuBar* menuBar=new QMenuBar(this);
	//menuBar->setGeometry(QRect(0,0,this->width(),24));
	// 	QMenu* editMenu=new QMenu(QString::fromLocal8Bit("插入文字"));
	// 	QMenu* saveMenu=new QMenu(QString::fromLocal8Bit("保存文字"));

	QAction* editAction = CreateAction("edit",QString::fromLocal8Bit("插入文字"));
	QAction* saveAction = CreateAction("save",QString::fromLocal8Bit("保存文字"));
	connect(editAction,SIGNAL(triggered()),this,SLOT(onEditTriggered()));
	connect(saveAction,SIGNAL(triggered()),this,SLOT(onSaveTriggered()));

	menuBar->addAction(editAction);
	menuBar->addAction(saveAction);

// 	menuBar->deleteLater();
// 	// 	editMenu->deleteLater();
// 	// 	saveMenu->deleteLater();
// 	editAction->deleteLater();
// 	saveAction->deleteLater();
}

void testTreeWidget::onTextEditCtrlClicked()
{
	int i=0;
}

void testTreeWidget::onEditTriggered()
{
	m_editClicked=!m_editClicked;
	if(m_editClicked==true)
	{
		this->setCursor(Qt::CrossCursor);
	}
	else
	{
		this->setCursor(Qt::ArrowCursor);
	}


}

void testTreeWidget::onSaveTriggered()
{

}


// void testTreeWidget::paintEvent(QPaintEvent *event)
// {
// 	QPainter* paint=new QPainter;
// 	
// }

void testTreeWidget::mousePressEvent(QMouseEvent* event)
{
	if(event->buttons()==Qt::LeftButton)
	{
		int event_x=event->pos().x();
		int event_y=event->pos().y();
		if(m_editClicked) //编辑文字按钮选中，新建文本框
		{
			EditLabel* texEdit=new EditLabel(this);
			texEdit->setGeometry(event->pos().rx(),event->pos().ry(),50,50);
			texEdit->m_textEdit->setFrameShape(QFrame::Panel);
			texEdit->m_textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
			texEdit->m_textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
			texEdit->show();
			m_textEditList.append(texEdit);
			m_editClicked=false;
		}
		else //编辑文字按钮没选中，选择文本框
		{
			this->setCursor(Qt::ArrowCursor);
			setEditEnable(false);
			int index=findListIndex(event->pos());
			if (index!=-1)
			{
				m_textEditList[index]->setEnabled(true);
				QRect rect=m_textEditList[index]->geometry();
					//调用childWidget
					EightPoints* points=EightPoints::instance();
					points->attachPointsAndTextWidget(m_textEditList[index]);

					//this->update();
/*				}*/
			}
			else
			{
				EightPoints* points=EightPoints::instance();
				points->showPoints(false);
			}
			

		}
		
	}
}

void testTreeWidget::mouseReleaseEvent(QMouseEvent* event)
{

}
void testTreeWidget::setEditEnable(bool enable)
{
	int count=m_textEditList.count();
	if(count>0)
	{
		for(int i=0;i<count;i++)
		{
			m_textEditList[i]->setEnabled(enable);
		}
	}

}
int testTreeWidget::findListIndex(QPoint point)
{
	int count=m_textEditList.count();
	int result=-1;
	for(int i=0;i<count;i++)
	{
		QRect rect=m_textEditList[i]->geometry();
		if(rect.contains(point))
		{
			result=i;
			
		}
	}
	return result;
}
QAction* testTreeWidget::CreateAction(QString objectName,QString text)
{
	QAction* action=new QAction(this);
	action->setObjectName(objectName);
	action->setText(text);
	return action;
}

// void testTreeWidget::paintEvent(QPaintEvent *event)
//{
// 	QPainter m_painter=new QPainter;
// 	m_painter->begin(this);
// 	m_painter->setPen(QPen(Qt::blue,4,Qt::DashLine));//设置画笔形式
// 	m_painter->setBrush(QBrush(Qt::red,Qt::SolidPattern));
// 	m_painter->drawRect(20,20,160,160);
// 	m_painter->end();
//}