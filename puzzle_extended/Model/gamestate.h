#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

class GameState
{
public:
	int time;
	int moves;

	GameState();
	GameState(std::istream&);

	friend std::ostream &operator <<(std::ostream&, const GameState&);
};

#endif // GAMESTATE_H
