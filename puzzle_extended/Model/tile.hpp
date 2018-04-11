#ifndef TILE_HPP
#define TILE_HPP

#include "image.hpp"
#include "location.h"

class Tile {
private:
	Image image;
	Location<int> location;
public:
	bool isEmpty;
public:
	Tile(Image, Location<int>);
};

#endif // TILE_HPP
