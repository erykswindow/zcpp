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
	ImageProcessor *imageProcessor;
	GameStateSaver *saver;
	Tile *_emptyTile = NULL;

public:
	GameStateController(Image image, int h, int v);
	GameStateController(Image _image, std::string _inputFileName);
	~GameStateController();

public:
	Game* getGame();
	Tile *tileWithLocation(Location<int> _loc);
	bool isGameFinished();
	void startGame();
	void moveIfPossible(Location<int> _loc);
	void moveIfPossible(MovementDirection dir);
	std::string generateSavefile();

private:
	std::vector<Tile *> generateTiles(std::vector<std::vector<Image>>);
	void shuffleTiles(std::vector<Tile *>, int);
	void replace(Location<int>, Location<int>, std::vector<Tile *>);
	Tile *tileWithLocation(Location<int>, std::vector<Tile *>);
	Tile *getEmptyTile();
	bool isInRange(Location<int> _loc);
	void setupGameWithImage(Image image, int h, int v);
};

#endif // GAMESTATECONTROLLER_H
