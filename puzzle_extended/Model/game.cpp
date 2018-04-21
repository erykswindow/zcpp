#include "game.h"

#define BOARD_KEY "\"board\":"
#define STATE_KEY "\"state\":"

Game::Game(Board *_board, GameState *_state): board(_board), state(_state) { }

Game::Game(std::string _input) {
		std::stringstream ss;
		ss.str(_input);

		while (ss.get() != '{') {}

		bool boardParsed = false;
		bool stateParsed = false;

		while (!(boardParsed && stateParsed)) {
			std::string currentKey = "";
			while (currentKey != BOARD_KEY && currentKey != STATE_KEY) {
				if (ss.peek() == ',') {
					ss.ignore();
					continue;
				}
				currentKey += ss.get();
			}

			if (currentKey == BOARD_KEY) {
				board = new Board(ss);
				boardParsed = true;
			} else if (currentKey == STATE_KEY) {
				state = new GameState(ss);
				stateParsed = true;
			}
		}

		while (ss.get() != EOF);
}

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
