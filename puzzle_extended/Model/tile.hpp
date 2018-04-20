#ifndef TILE_HPP
#define TILE_HPP

#include <iostream>
#include "location.h"

class Tile {
private:
	Location<int> location;
	Location<int> desiredLocation;

public:
	bool isEmpty;

public:
	Tile(Location<int>);
	Tile(std::istream&);

public:
	Location<int> getLocation();
	void setLocation(Location<int>);
	Location<int> getDesiredLocation();

	friend std::ostream &operator <<(std::ostream&, const Tile&);
};

std::vector<Tile *> generateTiles(std::istream&);
Location<int> generateLocation(std::istream&);

#endif // TILE_HPP
