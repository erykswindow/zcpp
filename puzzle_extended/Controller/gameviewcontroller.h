#ifndef GAMEVIEWCONTROLLER_H
#define GAMEVIEWCONTROLLER_H
#include <QGraphicsScene>
#include <QKeyEvent>

#include "controller.h"
#include "gamestatecontroller.h"

class GameViewController: public Controller {
private:
	GameStateController *stateController;
	std::vector<QGraphicsItem *> currentItems;
	QSize screenSize;
	QGraphicsScene *scene;

public:
	GameViewController(Image, int, int);
	~GameViewController();

public:
	void readInput(QWidget *);
	void setScene(QGraphicsScene *);
	void setScreenSize(QSize);
	void handleClick(QPoint);
	void handleKeboard(QKeyEvent*);
	void start();
	void handleSave();

public slots:

private:
	void resetItems();
	void redraw();
};

#endif // GAMEVIEWCONTROLLER_H
