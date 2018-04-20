#ifndef GAMESTATECONTROLLER_H
#define GAMESTATECONTROLLER_H

#include "Controller/controller.h"
#include "Utilities/imageprocessor.hpp"
#include "Utilities/gamestatesaver.h"
#include "Model/game.h"
#include "Model/direction.h"

class GameStateController: public Controller {
private:
	Game *game;
	GameStateSaver *saver;
	Tile *_emptyTile = NULL;

public:
	GameStateController(int h, int v);
	GameStateController();
	~GameStateController();

public:
	Game* getGame();
	Tile *tileWithLocation(Location<int> _loc);
	bool isGameFinished();
	void startGame();
	void moveIfPossible(Location<int> _loc);
	void moveIfPossible(MovementDirection dir);
	void generateSavefile();

private:
	std::vector<Tile *> generateTiles(int, int);
	void shuffleTiles(std::vector<Tile *>, int);
	void replace(Location<int>, Location<int>, std::vector<Tile *>);
	Tile *tileWithLocation(Location<int>, std::vector<Tile *>);
	Tile *getEmptyTile();
	bool isInRange(Location<int>);
	void setupGame(int, int);
};

#endif // GAMESTATECONTROLLER_H
