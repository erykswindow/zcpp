#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H
#include "range.h"

int random(int from, int to) { return from + rand() % (to - from + 1); }
template<class T> T randomOr(T first, T second) { return rand() % 2 ? first : second; }
//template<class T> bool inRange(T _val, T start, T end, bool inclusive) {
//	if inclusive {
//		return _val <= start && val <= end;
//	} else {
//		return _vale < start && val > end;
//	}
//}


template<class T> bool contains(Range<T> range, T _val) {
	return  (_val <= range.top) && (_val >= range.bottom);
}

#endif // HELPERFUNCTIONS_H
