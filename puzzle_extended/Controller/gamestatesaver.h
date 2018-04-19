#ifndef GAMESTATESAVER_H
#define GAMESTATESAVER_H

#include "Model/game.h"

class GameStateSaver
{
public:
	GameStateSaver();
	void saveGame(std::string filename, Game *game);
	void loadGame(std::string filename, Game *game);
};

#endif // GAMESTATESAVER_H
