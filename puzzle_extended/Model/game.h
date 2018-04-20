#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "board.hpp"
#include "gamestate.h"

class Game {
public:
	Board *board;
	GameState *state;

public:
	Game(Board*, GameState*);
	Game(std::string);
	~Game();

	friend std::ostream &operator <<(std::ostream&, const Game&);
};

#endif // GAME_H
