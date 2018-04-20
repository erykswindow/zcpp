#include "game.h"

Game::Game(Board *_board, GameState *_state): board(_board), state(_state) { }

Game::~Game() {
	delete board;
	delete state;
}

std::ostream &operator <<(std::ostream &os, const Game &game) {
	os << "{"
	   << "\"board\":" << (*game.board) << ","
	   << "\"state\":" << (*game.state)
	   << "}";
	return os;
}
