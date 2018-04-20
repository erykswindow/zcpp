#include "board.hpp"

#define WIDTH_KEY "\"width\":"
#define HEIGHT_KEY "\"height\":"
#define TILES_KEY "\"tiles\":"


Board::Board(std::vector<Tile *> _tiles): height(0), width(0), tiles(_tiles) {
	for (std::vector<Tile *>::iterator i = tiles.begin(); i != tiles.end(); i++) {
		Tile *tile = *i;
		Location<int> loc  = tile -> getLocation();
		height = std::max(height, loc.vertical + 1);
		width = std::max(width, loc.horizontal + 1);
	}
}


Board::Board(std::istream &_input) {
	while (_input.get() != '{') {}

	bool parsedHeight = false;
	bool parsedWidth = false;
	bool parsedTiles = false;

	while(!(parsedHeight && parsedWidth && parsedTiles)) {
		std::string currentKey = "";
		while (currentKey != HEIGHT_KEY && currentKey != WIDTH_KEY && currentKey != TILES_KEY) {
			if (_input.peek() == ',') {
				_input.ignore();
				continue;
			}
			currentKey += _input.get();
		}

		std::string valueBuf = "";
		if (currentKey == HEIGHT_KEY || currentKey == WIDTH_KEY){
			while (_input.peek() != ',' || _input.peek() == '}') {
				valueBuf += _input.get();
			}
		}
		if (currentKey == HEIGHT_KEY) {
			height = std::stoi(valueBuf);
			parsedHeight = true;
		} else if (currentKey == WIDTH_KEY) {
			width = std::stoi(valueBuf);
			parsedWidth = true;
		} else if (currentKey == TILES_KEY) {
			tiles = generateTiles(_input);
			parsedTiles = true;
		}
	}
	while (_input.get() != '}') {}
}


Board::~Board() {
	for (size_t i = 0; i < tiles.size(); i++) {
		delete tiles[i];
	}
}

std::ostream &operator <<(std::ostream &os, const Board &board) {

	os << "{"
	   << WIDTH_KEY << board.width << ","
	   << HEIGHT_KEY << board.height << ","
	   << TILES_KEY
		 <<"[";
	std::vector<Tile *> tiles = board.tiles;
	for (std::vector<Tile *>::iterator i = tiles.begin(); i != tiles.end(); i++)  {
		Tile *tile = *i;
		os << (*tile)
		   <<",";
	}
	os << "]" << "}";
	return os;
}
