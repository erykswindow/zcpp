#include <fstream>
#include <iostream>
#include "gamestatesaver.h"

#define SAVEFILE_NAME "amazingsavefile"

GameStateSaver::GameStateSaver() { }

void GameStateSaver::saveGame(Game *_game) {
	std::ofstream file(SAVEFILE_NAME);
	if (file.good()) {
		file << *_game;;
	}
	file.close();
}

void GameStateSaver::loadGame(Game **_game) {
	std::ifstream file(SAVEFILE_NAME);
	if (file.good()) {
		std::string input;
		file >> std::skipws >> input;
		Game *g = new Game(input);
		*_game = g;
	}
	file.close();
}


