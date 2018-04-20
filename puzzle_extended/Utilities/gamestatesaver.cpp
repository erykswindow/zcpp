#include <sstream>
#include <iostream>
#include "gamestatesaver.h"

#define LOCATION_DELIMITER "|"

GameStateSaver::GameStateSaver() { }

void GameStateSaver::saveGame(std::string filename, Game *game) {
	std::vector<Tile *> tiles = game -> board -> tiles;
	std::string status = "";

	for (std::vector<Tile *>::iterator i = tiles.begin(); i != tiles.end(); i++)  {
		Tile *tile = *i;
		Location<int> loc = tile -> getLocation();
		Location<int> des = tile -> getDesiredLocation();
		std::ostringstream stringStream;
		stringStream << "des:" << "{" << des.horizontal << des.vertical << "}";
		stringStream << "loc:" << "{" << loc.horizontal << des.vertical << "}";
		stringStream << LOCATION_DELIMITER;
		std::string tileString = stringStream.str();
		status += tileString;
	}
	std::cout << status;
}

void GameStateSaver::loadGame(std::string filename, Game *game) {

}
