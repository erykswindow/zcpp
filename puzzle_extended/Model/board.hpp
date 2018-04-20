#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include "tile.hpp"

class Board {
public:
	int width;
	int height;
	std::vector<Tile *> tiles;

public:
	Board(std::vector<Tile *>);
	~Board();

	friend std::ostream &operator <<(std::ostream&, const Board&);
};


#endif // BOARD_HPP


