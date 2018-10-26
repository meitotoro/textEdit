#ifndef EIGHTPOINTS_H
#define EIGHTPOINTS_H

#include <QWidget>
#include "point.h"
#include "editlabel.h"
#include <QLabel>
#include <QMap>

class EightPoints : public QWidget
{
	Q_OBJECT

public:
	static EightPoints* instance();
	~EightPoints();
	void attachPointsAndTextWidget(EditLabel* labelWidget);
	void showPoints(bool show);
	void onHandleDragged(Point::Position pos, int to_x, int to_y);
	static void setParent(QWidget* parent);
	static QWidget* m_parent;

private:
	
	static EightPoints* m_self;
	EightPoints();
	EditLabel* m_labelwidget;
	std::map<Point::Position,Point*> m_pointMap;
	Point::Position getDiagonalPos(Point::Position pos);
signals:
	void SlectedLabelChanged(EditLabel* label);

private:
	
};

#endif // EIGHTPOINTS_H
