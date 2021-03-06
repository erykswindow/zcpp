#include <cmath>
#include <sstream>
#include "gamestatecontroller.h"
#include "Model/board.hpp"
#include "Model/location.h"
#include "Model/direction.h"
#include "Utilities/helperfunctions.h"

//Constructors & Destructors
GameStateController::GameStateController(int _h, int _v) {
	saver = new GameStateSaver;
	this -> setupGame(_h, _v);
}

GameStateController::GameStateController() {
	saver = new GameStateSaver;
	saver -> loadGame(&game);
}

GameStateController::~GameStateController(){
	delete game;
	delete saver;
}

//Public methods
bool GameStateController::isGameFinished() {
	typedef std::vector<Tile *> TV;
	TV tiles = game -> board -> tiles;
	bool finished = true;
	for (TV::iterator i = tiles.begin(); i != tiles.end(); i++) {
		Tile *tile = *i;
		bool isTileRight = (tile->getLocation() == tile -> getDesiredLocation());
		finished &= isTileRight;
	}
	return finished;
}

Game *GameStateController::getGame() {
	return game;
}

std::vector<Tile *> GameStateController::generateTiles(int _h, int _v) {
	std::vector<Tile *> tiles;
	for(int h = 0; h < _h; h++) {
		for(int v = 0; v < _v; v++) {
			Location<int> location = {h, v};
			Tile *tile = new Tile(location);
			tiles.push_back(tile);
		}
	}
	tiles[tiles.size() - 1] -> isEmpty = true;
	return tiles;
}

GameState GameStateController::currentState() {
	return *(game ->state);
}

void GameStateController::incrementTimer() {
	game -> state -> incrementTime();
}

void GameStateController::moveIfPossible(Location<int> _loc) {
	Tile *emptyTile = getEmptyTile();
	Location<int> currentEmpty = emptyTile -> getLocation();
	int hDiff = _loc.horizontal - currentEmpty.horizontal;
	int vDiff = _loc.vertical - currentEmpty.vertical;
	int m = abs(hDiff) + abs(vDiff);
	if (m == 1 && isInRange(_loc)) {
		replace(currentEmpty, _loc, game -> board -> tiles);
		game -> state -> incrementMoves();
	}
}

void GameStateController::moveIfPossible(MovementDirection _direction) {
	Tile *emptyTile = getEmptyTile();
	Location<int> currentEmpty = emptyTile -> getLocation();
	Location<int> newEmpty = currentEmpty;

	switch (_direction) {
	case up:
		newEmpty.vertical -= 1;
		break;
	case down:
		newEmpty.vertical += 1;
		break;
	case left:
		newEmpty.horizontal -= 1;
		break;
	case right:
		newEmpty.horizontal += 1;
		break;
	}

	if (isInRange(newEmpty)) {
		replace(currentEmpty, newEmpty, game -> board -> tiles);
		game -> state -> incrementMoves();
	}
}

void GameStateController::startGame() {
	std::vector<Tile *> tiles = game -> board -> tiles;
	int power = pow(3, fmax(game -> board -> width, game -> board -> height));
	int moves = fmax(400, power);
	this -> shuffleTiles(tiles, moves);
}

void GameStateController::replace(Location<int> _loc1, Location<int> _loc2, std::vector<Tile *> _tiles) {
	Tile *tile1 = tileWithLocation(_loc1, _tiles);
	Tile *tile2 = tileWithLocation(_loc2, _tiles);
	tile2 -> setLocation(_loc1);
	tile1 -> setLocation(_loc2);
}

bool GameStateController::isInRange(Location<int> _loc) {
	Board* b = game -> board;
	int maxH = b -> width - 1;
	int maxV = b -> height - 1;
	return contains({0, maxH}, _loc.horizontal) && contains({0, maxV}, _loc.vertical);
}

void GameStateController::setupGame(int _h, int _v) {
	std::vector<Tile *> tiles = generateTiles(_h, _v);
	Board *board = new Board(tiles);
	GameState *state = new GameState();
	game = new Game(board, state);
}

void GameStateController::shuffleTiles(std::vector<Tile *> _tiles, int _moves) {
	Location<int> emptyLocation = getEmptyTile() -> getLocation();

	for (int i = 0; i < _moves; i++) {

		Direction dir = randomOr(horizontal, vertical);
		int movement = randomOr(-1, 1);

		Location<int> moveLocation;

		switch(dir) {
		case horizontal:
			moveLocation = {emptyLocation.horizontal + movement, emptyLocation.vertical };
			break;
		case vertical:
			moveLocation = {emptyLocation.horizontal, emptyLocation.vertical  + movement };
			break;
		default:
			break;
		}

		if (isInRange(moveLocation)) {
			replace(emptyLocation, moveLocation, _tiles);
			emptyLocation = moveLocation;
		} else {
			i--;
		}
	}
}

Tile *GameStateController::tileWithLocation(Location<int> _loc, std::vector<Tile *> _tiles) {
	for (std::vector<Tile *>::iterator i = _tiles.begin(); i != _tiles.end(); i++) {
		Tile *tile = *i;
		if (tile->getLocation() == _loc) {
			return tile;
		}
	}
	return NULL;
}

Tile *GameStateController::tileWithLocation(Location<int> _loc) {
	return tileWithLocation(_loc, this -> game -> board -> tiles);
}

Tile *GameStateController::getEmptyTile() {
	if (_emptyTile != NULL) { return _emptyTile; }
	std::vector<Tile *> tiles = this -> game -> board -> tiles;
	for (std::vector<Tile *>::iterator i = tiles.begin(); i != tiles.end(); i++) {
		Tile *tile = *i;
		if (tile -> isEmpty) {
			_emptyTile = tile;
			return getEmptyTile();
		}
	}
	return NULL;
}

void GameStateController::generateSavefile() {
	this -> saver -> saveGame(this -> game);
}
