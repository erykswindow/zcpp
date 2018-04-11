#ifndef GAME_H
#define GAME_H

#include "board.hpp"
#include "gamestate.h"


class Game {
public:
	Board *board;
	GameState *state;

public:
	Game(Board*, GameState*);
	~Game();
};

#endif // GAME_H
