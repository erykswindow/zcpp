#include <iostream>
#include "gamestate.h"

#define MOVES_KEY "\"moves\":"
#define TIME_KEY "\"time\":"

GameState::GameState(): moves(0), time(0) { }

GameState::GameState(std::istream &_input) {
	while (_input.get() != '{') {}

	int parsedMoves = false;
	int parsedTime = false;

	while (!(parsedMoves && parsedTime)) {
		std::string currentKey = "";
		while (currentKey != MOVES_KEY && currentKey != TIME_KEY) {
			if (_input.peek() == ',') {
				_input.ignore();
				continue;
			}
			currentKey += _input.get();
		}
		std::string valueBuf = "";
		while(_input.peek() != ',' && _input.peek() != '}') {
			valueBuf += _input.get();
		}
		if (currentKey == MOVES_KEY) {
			moves = std::stoi(valueBuf);
			parsedTime = true;
		} else if (currentKey == TIME_KEY) {
			time = std::stoi(valueBuf);
			parsedMoves = true;
		}
	}

}

void GameState::incrementTime() {
	time++;
}

void GameState::incrementMoves() {
	moves++;
}

std::ostream &operator <<(std::ostream &os, const GameState &state) {
	os << "{"
	   << "\"moves\":" << state.moves << ","
	   << "\"time\":" << state.time
	   << "}";
	return os;
}
