#include "tile.hpp"
#include "location.h"
#include <string>

#define DESIRED_LOCATION_KEY "\"desired_location\":"
#define LOCATION_KEY "\"location\":"

Location<int> makeLocation(std::istream&);

Tile::Tile(Image _image, Location<int> _location): location(_location), desiredLocation(_location) {
	image = _image;
	isEmpty = false;
}

Tile::Tile(std::istream &_input) {
	while (_input.get() != '{') {}

	bool parsedLocation = false;
	bool parsedDesiredLocation = false;

	while(!(parsedDesiredLocation && parsedLocation)) {
		std::string currentKey = "";
		while (currentKey != DESIRED_LOCATION_KEY && currentKey != LOCATION_KEY) {
			if (_input.peek() == ',') {
				_input.ignore();
				continue;
			}
			currentKey += _input.get();
		}
		if (currentKey == DESIRED_LOCATION_KEY) {
			desiredLocation = makeLocation(_input);
			parsedDesiredLocation = true;
		} else if (currentKey == LOCATION_KEY) {
			location = makeLocation(_input);
			parsedLocation = true;
		}
	}
	while (_input.get() != '}') {}
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

std::ostream &operator <<(std::ostream &os, const Tile &tile) {
	os << "{"
		<< DESIRED_LOCATION_KEY << tile.desiredLocation << ","
		<< LOCATION_KEY << tile.location
		<<"}";
	return os;
}

std::vector<Tile *> generateTiles(std::istream &_input) {
	std::vector<Tile *> tiles;
	while (_input.get() != '[') {}
	while (_input.peek() != ']') {
		if (_input.peek() == ',') {
			_input.ignore();
			continue;
		}
		tiles.push_back(new Tile(_input));
	}
	_input.ignore();
	return tiles;
}

Location<int> makeLocation(std::istream &_input) {
	typedef int T;
	T hor;
	T vert;
	while(_input.get() != '{') {
		_input.ignore();
	}

	bool parsedHorizontal = false;
	bool parsedVertical = false;

	while (!(parsedHorizontal && parsedVertical)) {
		std::string currentKey = "";
		while (currentKey != HORIZONTAL_KEY && currentKey != VERTICAL_KEY) {
			if (_input.peek() == ',') {
				_input.ignore();
				continue;
			}
			currentKey += _input.get();
		}

		std::string valueBuff = "";
		while (_input.peek() != ',' && _input.peek() != '}') {
			valueBuff += _input.get();
		}

		if (currentKey == HORIZONTAL_KEY) {
			hor = std::stoi(valueBuff);
			parsedHorizontal = true;
		}

		if (currentKey == VERTICAL_KEY) {
			vert = std::stoi(valueBuff);
			parsedVertical = true;
		}
	}

	while(_input.get() != '}') {}
	return { hor, vert };
}
