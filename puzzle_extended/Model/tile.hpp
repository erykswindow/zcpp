#ifndef TILE_HPP
#define TILE_HPP

#include "image.hpp"
#include "location.h"

class Tile {
private:
	Location<int> location;
	Image image;
public:
	bool isEmpty;

public:
	Tile(Image, Location<int>);

public:
	Image getImage();
};

#endif // TILE_HPP
