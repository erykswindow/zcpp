#ifndef GAMESTATECONTROLLER_H
#define GAMESTATECONTROLLER_H
#include "imageprocessor.hpp"
#include "Model/game.h"
#include "Model/direction.h"

class GameStateController {
private:
	Game *game;
	ImageProcessor *imageProcessor;
	Tile *_emptyTile = NULL;

public:
	GameStateController();
	~GameStateController();

public:
	Game* getGame();
	Tile *tileWithLocation(Location<int> _loc);

	void setupGameWithImage(Image);
	bool isGameFinished();
	void startGame();
	void moveIfPossible(Location<int> _loc);
	void moveIfPossible(KeyboardDirection dir);

private:
	std::vector<Tile *> generateTiles(std::vector<std::vector<Image>>);
	void shuffleTiles(std::vector<Tile *>, int);
	void replace(Location<int>, Location<int>, std::vector<Tile *>);
	Tile *tileWithLocation(Location<int>, std::vector<Tile *>);
	Tile *getEmptyTile();
	bool isInRange(Location<int> _loc);
};

#endif // GAMESTATECONTROLLER_H
