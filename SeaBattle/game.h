#ifndef __GAME
#define __GAME

#include "defs.h"
#include "map.h"

class Game {
	friend class GameTest;
private:
protected:
	Map* map;
public:
	Game();
	virtual ~Game();
};

#endif
