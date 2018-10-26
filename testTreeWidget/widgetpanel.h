#ifndef WIDGETPANEL_H
#define WIDGETPANEL_H

#include <QWidget>
#include "ui_widgetpanel.h"

class WidgetPanel : public QWidget
{
	Q_OBJECT

public:
	WidgetPanel(QWidget *parent = 0);
	~WidgetPanel();

private:
	Ui::WidgetPanel ui;
};

#endif // WIDGETPANEL_H
