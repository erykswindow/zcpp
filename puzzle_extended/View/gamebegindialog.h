#ifndef GAMEBEGINDIALOG_H
#define GAMEBEGINDIALOG_H

#include <QGraphicsScene>
#include "Model/image.hpp"
#include <QWidget>


class GameBeginDialog
{
public:
	GameBeginDialog();
	QGraphicsScene *scene;
	Image currentImage;

	void setDefaultImage();
	void setImage(Image);
	virtual void drawCurrentImage() {};
};

#endif // GAMEBEGINDIALOG_H
