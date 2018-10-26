#include "circlepoint.h"

CirclePoint::CirclePoint(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//this->update();
// 	int x=parent->x();
// 	int y=parent->y();
// 	int width=parent->width();
// 	int height=parent->height();
	//this->setGeometry(parent->x(),parent->y(),parent->width(),parent->height());
}

CirclePoint::~CirclePoint()
{

}

void CirclePoint::setPosition(QPoint point)
{
	m_point=point;
	this->setGeometry(m_point.x(),m_point.y(),160,160);
}
void CirclePoint::paintEvent(QPaintEvent *event)
{
	m_painter=new QPainter;
	m_painter->begin(this);
	m_painter->setPen(QPen(Qt::blue,4,Qt::DashLine));//ÉèÖÃ»­±ÊĞÎÊ½
	m_painter->setBrush(QBrush(Qt::red,Qt::SolidPattern));
	m_painter->drawRect(0,0,160,160);
	m_painter->end();
	
}
