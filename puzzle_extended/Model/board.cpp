#include "board.hpp"

Board::Board(std::vector<Tile *> _tiles): height(0), width(0) {
    tiles = _tiles;
	for (std::vector<Tile *>::iterator i = tiles.begin(); i != tiles.end(); i++) {
		Tile *tile = *i;
		Location<int> loc  = tile -> getLocation();
		height = std::max(height, loc.vertical + 1);
		width = std::max(width, loc.horizontal + 1);
	}
}

Board::~Board() {
	for (int i = 0; i < tiles.size(); i++) {
		delete tiles[i];
	}
}
