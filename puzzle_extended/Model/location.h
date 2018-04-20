#ifndef LOCATION_H
#define LOCATION_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

#define HORIZONTAL_KEY "\"horizontal\":"
#define VERTICAL_KEY "\"vertical\":"

template<class T> struct Location {
	T horizontal;
	T vertical;
};

template<class T> bool operator ==(Location<T> _loc1, Location<T> _loc2) {
	return _loc1.horizontal == _loc2.horizontal
			&& _loc1.vertical == _loc2.vertical;
}

template<class T> std::ostream& operator << (std::ostream& os, const Location<T>& loc) {
	os <<"{"
	  << HORIZONTAL_KEY << loc.horizontal << ","
	  << VERTICAL_KEY << loc.vertical
	  << "}";
	return os;
}

#endif // LOCATION_H
