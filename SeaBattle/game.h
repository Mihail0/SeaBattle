#ifndef __GAME
#define __GAME

#include "defs.h"
#include "map.h"

class Game {
	friend class GameTest;
private:
protected:
public:
	Map* map;
	Game();
	virtual ~Game();
};

#endif
