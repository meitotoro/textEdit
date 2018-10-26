#ifndef POINT_H
#define POINT_H

#include <QWidget>
#include <QPoint>
#include <QSize>
#include "editlabel.h"


class Point : public QWidget
{
	Q_OBJECT

public:
	enum Position {
		Center = 0,
		Top = 1 << 4,
		Bottom = 2 << 4,
		Left = 1,
		Right = 2,
		LeftTop = Left | Top,
		RightTop = Right | Top,
		RightBottom = Right | Bottom,
		LeftBottom = Left | Bottom,
	};
	Point(Position pos);
	~Point();

	static const QSize SIZE;

protected:
	void paintEvent(QPaintEvent *event) override;
	void mouseMoveEvent(QMouseEvent* event);
	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);

private:
	bool m_mousePressed;
	Position m_position;
	QPoint m_ref_pos;
};

Point::Position horizontalPos(Point::Position p); // 水平分量
Point::Position verticalPos(Point::Position p);   // 垂直分量

#endif // POINT_H
