#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
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
	Tile(std::istream&);

public:
	Image getImage();
	Location<int> getLocation();
	void setLocation(Location<int>);
	Location<int> getDesiredLocation();

	friend std::ostream &operator <<(std::ostream&, const Tile&);
};

std::vector<Tile *> generateTiles(std::istream&);

#endif // TILE_HPP
