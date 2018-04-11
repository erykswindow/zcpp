#include "board.hpp"

Board::Board(std::vector<Tile *> _tiles) {
    tiles = _tiles;
}

Board::~Board() {
	for (int i = 0; i < tiles.size(); i++) {
		delete tiles[i];
	}
}
