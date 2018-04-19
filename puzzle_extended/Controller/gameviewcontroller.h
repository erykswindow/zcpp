#ifndef GAMEVIEWCONTROLLER_H
#define GAMEVIEWCONTROLLER_H
#import "viewcontroller.h"
#import "gamestatecontroller.h"

#include <QGraphicsScene>
#include <QKeyEvent>

class GameViewController: public ViewController {
private:
	GameStateController *stateController;
	std::vector<QGraphicsItem *> _currentItems;
	QSize _screenSize;
	QGraphicsScene *_scene;

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
