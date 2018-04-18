#ifndef TILE_HPP
#define TILE_HPP

#include "image.hpp"
#include "location.h"

class Tile {
private:
	Location<int> location;
	Location<int> desiredLocation;
	Image image;
public:
	bool isEmpty;

public:
	Tile(Image, Location<int>);

public:
	Image getImage();
	Location<int> getLocation();
	void setLocation(Location<int>);
	Location<int> getDesiredLocation();
};

#endif // TILE_HPP
