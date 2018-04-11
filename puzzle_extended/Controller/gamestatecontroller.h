#ifndef GAMESTATECONTROLLER_H
#define GAMESTATECONTROLLER_H
#include "imageprocessor.hpp"
#include "Model/game.h"


class GameStateController {
private:
	Game *game;
	ImageProcessor *imageProcessor;

public:
	GameStateController();
	~GameStateController();

public:
	void setupGameWithImage(Image);

private:
	std::vector<Tile *> generateTiles(std::vector<std::vector<Image> > images);
};

#endif // GAMESTATECONTROLLER_H
