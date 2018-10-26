#include "eightpoints.h"
#include <QPainter>
#include <QMap>
#include <iostream>
EightPoints::EightPoints() :
	m_labelwidget(nullptr)
{
	static Point::Position all_pos[] = {
		Point::Top,
		Point::Bottom,
		Point::Left,
		Point::Right,
		Point::LeftTop,
		Point::LeftBottom,
		Point::RightTop,
		Point::RightBottom,
	};
	for (int i = 0; i < 8; ++i) {
		Point::Position pos = all_pos[i];
		m_pointMap[pos] = new Point(pos);
	}

	showPoints(false);

}



EightPoints* EightPoints::m_self = NULL;

QWidget* EightPoints::m_parent = NULL;

void EightPoints::setParent(QWidget* parent)
{

	EightPoints* p = EightPoints::instance();
	if (p != NULL)
	{
		EightPoints::m_parent = parent;
		std::map<Point::Position, Point*>::iterator iter = p->m_pointMap.begin();
		while (iter != p->m_pointMap.end())
		{
			Point* p = iter->second;
			p->setParent(m_parent);
			iter++;
		}
	}

}

EightPoints* EightPoints::instance()
{
	if (m_self == NULL)
	{
		m_self = new EightPoints();
		m_self->setParent(m_parent);
	}
	return m_self;
}

EightPoints::~EightPoints()
{

}

void EightPoints::attachPointsAndTextWidget(EditLabel* labelWidget)
{
	if (labelWidget != NULL)
	{
		m_labelwidget = labelWidget;
		QRect rect = m_labelwidget->geometry();
		int x1 = rect.left();
		int y1 = rect.top();
		int x2 = rect.right();
		int y2 = rect.bottom();
		QPoint leftTop_Point(rect.left() - 8, rect.top() - 8);
		QPoint rightTop_Point(rect.right(), rect.top() - 8);
		QPoint leftBottom_Point(rect.left() - 8, rect.bottom());
		QPoint rightBottom_Point(rect.right(), rect.bottom());
		QPoint top_Point((rect.left() + rect.right()) / 2, rect.top() - 8);
		QPoint left_Point(rect.left() - 8, (rect.top() + rect.bottom()) / 2);
		QPoint bottom_Point((rect.left() + rect.right()) / 2, rect.bottom());
		QPoint right_Point(rect.right(), (rect.top() + rect.bottom()) / 2);

		m_pointMap[Point::LeftTop]->move(leftTop_Point);
		m_pointMap[Point::LeftBottom]->move(leftBottom_Point);
		m_pointMap[Point::RightTop]->move(rightTop_Point);
		m_pointMap[Point::RightBottom]->move(rightBottom_Point);
		m_pointMap[Point::Top]->move(top_Point);
		m_pointMap[Point::Right]->move(right_Point);
		m_pointMap[Point::Bottom]->move(bottom_Point);
		m_pointMap[Point::Left]->move(left_Point);

		showPoints(true);

		emit SlectedLabelChanged(labelWidget);
	}
}

void EightPoints::showPoints(bool show)
{
	std::map<Point::Position, Point*>::iterator iter = m_pointMap.begin();
	for (iter; iter != m_pointMap.end(); ++iter)
	{
		Point* p = iter->second;
		p->setVisible(show);
	}

}
void EightPoints::onHandleDragged(Point::Position pos, int dx, int dy)
{
	Point* pointToMove = m_pointMap[pos];

	int toWidth = m_labelwidget->width();
	int toHeight = m_labelwidget->height();
	int target_pos_x = m_labelwidget->pos().x();
	int target_pos_y = m_labelwidget->pos().y();

	QRect rectLabel = m_labelwidget->geometry();
	if (horizontalPos(pos) == Point::Left) {
		toWidth -= dx;
		target_pos_x += dx;
		std::cout << "left ";
	}
	else if (horizontalPos(pos) == Point::Right) {
		toWidth += dx;
		std::cout << "right ";
	}
	if (verticalPos(pos) == Point::Top) {
		toHeight -= dy;
		target_pos_y += dy;
		std::cout << "top";
	}
	else if (verticalPos(pos) == Point::Bottom) {
		toHeight += dy;
		std::cout << "bottom";
	}
	std::cout << std::endl;
	m_labelwidget->move(target_pos_x, target_pos_y);
	m_labelwidget->resize(toWidth, toHeight);
	m_labelwidget->update();
	//更新labelwidget周围八个点的位置
	attachPointsAndTextWidget(m_labelwidget);
}
