#ifndef GAMESTATESAVER_H
#define GAMESTATESAVER_H

#include "Model/game.h"

class GameStateSaver
{
public:
	GameStateSaver();
	void saveGame(Game*);
	void loadGame(Game**);
};

#endif // GAMESTATESAVER_H
