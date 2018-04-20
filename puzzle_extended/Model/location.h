#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <sstream>
#include <string>

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
	  << "\"horizontal\":" << loc.horizontal << ","
	  << "\"vertical\":" << loc.vertical
	  << "}";
	return os;
}

#endif // LOCATION_H
