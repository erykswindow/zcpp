#ifndef GAMEVIEWCONTROLLER_H
#define GAMEVIEWCONTROLLER_H
#import "viewcontroller.h"
#import "gamestatecontroller.h"

class GameViewController: public ViewController {
private:
	GameStateController *stateController;

public:
	GameViewController();

public:
	void readInput(QWidget *);

};

#endif // GAMEVIEWCONTROLLER_H
