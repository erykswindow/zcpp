#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H
#include "Model/range.h"

int random(int from, int to) { return from + rand() % (to - from + 1); }

template<class T> T randomOr(T first, T second) { return rand() % 2 ? first : second; }

#endif // HELPERFUNCTIONS_H
