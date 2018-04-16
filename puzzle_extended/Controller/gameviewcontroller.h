#ifndef GAMEVIEWCONTROLLER_H
#define GAMEVIEWCONTROLLER_H
#import "viewcontroller.h"
#import "gamestatecontroller.h"

#include <QGraphicsScene>

class GameViewController: public ViewController {
private:
	GameStateController *stateController;

public:
	GameViewController();

public:
	void readInput(QWidget *);
	void drawIn(QGraphicsScene *_graphicsScene);
};

#endif // GAMEVIEWCONTROLLER_H
