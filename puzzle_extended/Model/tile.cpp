#include "tile.hpp"

Tile::Tile(Image _image, Location<int> _location): location(_location), desiredLocation(_location) {
	image = _image;
	isEmpty = false;
}

Image Tile::getImage() {
	return this -> image;
}

Location<int> Tile::getLocation() {
	return location;
}

void Tile::setLocation(Location<int> _loc)
{
	location = _loc;
}

Location<int> Tile::getDesiredLocation()
{
	return desiredLocation;
}
