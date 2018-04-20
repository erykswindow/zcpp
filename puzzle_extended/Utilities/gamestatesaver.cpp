#include <fstream>
#include "gamestatesaver.h"

#define SAVEFILE_NAME "amazingsavefile"

GameStateSaver::GameStateSaver() { }

void GameStateSaver::saveGame(std::string filename, Game *game) {
	std::ofstream file(SAVEFILE_NAME);
	if (file.good()) {
		file << *game;;
	}
	file.close();
}

void GameStateSaver::loadGame(std::string filename, Game *game) {
	std::istream file(SAVEFILE_NAME);
	if (file.good()) {
		std::cout << file;
	}
	file.close();
}
