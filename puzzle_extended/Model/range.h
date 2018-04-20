#ifndef RANGE_H
#define RANGE_H

template<class T> struct Range {
	T bottom;
	T top;
};

template<class T> bool contains(Range<T> range, T _val) {
	return  (_val <= range.top) && (_val >= range.bottom);
}

#endif // RANGE_H
