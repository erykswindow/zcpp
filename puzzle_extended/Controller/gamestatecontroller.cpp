#include "gamestatecontroller.h"
#include "Model/board.hpp"

GameStateController::GameStateController() {
	imageProcessor = new ImageProcessor;
}

void GameStateController::setupGameWithImage(Image image) {
	std::vector<std::vector<Image>> images = imageProcessor -> divideImage(image, 4, 4);
	std::vector<Tile *> tiles = generateTiles(images);
	Board *board = new Board(tiles);
	GameState *state = new GameState();
	game = new Game(board, state);
}

std::vector<Tile *> GameStateController::generateTiles(std::vector<std::vector<Image>> images) {
	std::vector<Tile *> tiles;

	for(int i = 0; i < images.size(); i++) {
		std::vector<Image> row = images[i];
		for(int j = 0; j < row.size(); j++) {
			Location<int> location = {j ,i};
			Tile *tile = new Tile(row[j], location);
			tiles.push_back(tile);
		}
	}
	return tiles;
}

GameStateController::~GameStateController(){
	delete game;
	delete imageProcessor;
}
