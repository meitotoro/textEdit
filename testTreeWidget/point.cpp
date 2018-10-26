#include <QtWidgets>
#include "point.h"
#include <QPainter>
#include "eightpoints.h"
#include <iostream>

const QSize Point::SIZE(8, 8);

Point::Point(Point::Position pos) :
	m_position(pos), m_mousePressed(false)
{
	resize(Point::SIZE);
	std::cout << "created: " << this << ", size: w=" << size().width() << ", h=" << size().height() << std::endl;
	setMouseTracking(true);
}

Point::~Point()
{

}

void Point::mousePressEvent(QMouseEvent* event)
{
	m_mousePressed = true;
	m_ref_pos = mapToParent(event->pos());
	std::cout << "pressed: " << this << ", size: w=" << size().width() << ", h=" << size().height() << std::endl;
	std::cout << "pressed: [" << horizontalPos(m_position) << "," << verticalPos(m_position) << "]" << std::endl;
}

void Point::mouseReleaseEvent(QMouseEvent* event)
{
	m_mousePressed = false;
	std::cout << "released: [" << horizontalPos(m_position) << "," << verticalPos(m_position) << "]" << std::endl;
}

void Point::paintEvent(QPaintEvent *event)
{
	QRect rect(QPoint(0, 0), Point::SIZE);
	QPainter painter(this);
	painter.fillRect(rect, Qt::black);
}

void Point::mouseMoveEvent(QMouseEvent* event)
{
	if (m_mousePressed) {
		std::cout << "moved: [" << horizontalPos(m_position) << "," << verticalPos(m_position) << "]" << std::endl;
		EightPoints* points = EightPoints::instance();
		QPoint curr_pos = mapToParent(event->pos());
		QPoint delta = curr_pos - m_ref_pos;
		std::cout << "delta: (" << delta.x() << "," << delta.y() << ")" << std::endl;
		m_ref_pos = mapToParent(event->pos());
		points->onHandleDragged(m_position, delta.x(), delta.y());
	}
}

Point::Position horizontalPos(Point::Position p)
{
	/*
	int horizontalMask = 0x0F; // 00001111
	int value = static_cast<int>(p);
	// e.g.
	// 00100001
	// ----^^^^
	// 00000001
	return static_cast<Point::Position>(value & horizontalMask);
	*/
	switch (p) {
	case Point::Left:
	case Point::LeftBottom:
	case Point::LeftTop:
		return Point::Left;
	case Point::Right:
	case Point::RightTop:
	case Point::RightBottom:
		return Point::Right;
	default:
		return Point::Center;
	}
}

Point::Position verticalPos(Point::Position p)
{
	/*
	int verticalMask = 0xF0; // 11110000
	int value = static_cast<int>(p);
	// e.g.
	// 00100001
	// ^^^^----
	// 00100000
	return static_cast<Point::Position>(value & verticalMask);
	*/
	switch (p) {
	case Point::Top:
	case Point::LeftTop:
	case Point::RightTop:
		return Point::Top;
	case Point::Bottom:
	case Point::LeftBottom:
	case Point::RightBottom:
		return Point::Bottom;
	default:
		return Point::Center;
	}
}
