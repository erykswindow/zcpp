#ifndef BOARD_HPP
#define BOARD_HPP

#import <vector>
#include "tile.hpp"


class Board {
public:
	std::vector<Tile *> tiles;

public:
	Board(std::vector<Tile *>);
	~Board();
};


#endif // BOARD_HPP


