#include <iostream>
#include "gamestate.h"

GameState::GameState(): moves(0), time(0) {

}

std::ostream &operator <<(std::ostream &os, const GameState &state) {
	os << "{"
	   << "\"moves\":" << state.moves << ","
	   << "\"time\":" << state.time
	   << "}";
	return os;
}
