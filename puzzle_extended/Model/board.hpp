#ifndef BOARD_HPP
#define BOARD_HPP

#import <vector>
#import "tile.hpp"


class Board {
public:
	std::vector<Tile *> tiles;

public:
	Board(std::vector<Tile *>);
	~Board();
};


#endif // BOARD_HPP


