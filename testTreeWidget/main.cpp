#include "testtreewidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	testTreeWidget w;
	w.show();
	return a.exec();
// 	QVideoWidget vedioWidget(&w);
// 	w.setCentralWidget(&vedioWidget);
// 	QMediaPlayer* mediaPlayer=new QMediaPlayer(&w);
// 	
// 	
// 	QMediaContent content(QUrl::fromLocalFile("C:\\GTDATA\\4Wildlife.wmv"));
// 	bool result=content.isNull();
// 	mediaPlayer->setMedia(content);
// 	mediaPlayer->setVideoOutput(&vedioWidget);
// 	w.show();
// 	mediaPlayer->play();
// 	return a.exec();
}

