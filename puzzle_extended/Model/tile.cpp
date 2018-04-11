#include "tile.hpp"

Tile::Tile(Image _image, Location<int> _location) {
	image = _image;
	location = _location;
	isEmpty = false;
}
