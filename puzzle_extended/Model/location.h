#ifndef LOCATION_H
#define LOCATION_H

template<class T> struct Location {
	T horizontal;
	T vertical;
};

template<class T> bool operator ==(Location<T> _loc1, Location<T> _loc2) {
	return _loc1.horizontal == _loc2.horizontal
			&& _loc1.vertical == _loc2.vertical;
}

#endif // LOCATION_H
