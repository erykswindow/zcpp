#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#import "Controller/gameviewcontroller.h"

namespace Ui {
class GameWidget;
}

class GameWidget : public QWidget
{
	Q_OBJECT
private:
	GameViewController *viewController;

public:
	GameWidget(QWidget *parent = 0, GameViewController *_viewController = 0);
	~GameWidget();
	virtual void show();

private:
	Ui::GameWidget *ui;
};

#endif // GAMEWIDGET_H
