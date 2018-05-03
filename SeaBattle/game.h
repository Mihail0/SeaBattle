#ifndef __GAME
#define __GAME

#include "defs.h"
#include "map.h"
#include "ship.h"
#include "shipcreator.h"

class Game {
	friend class GameTest;
private:
protected:
	Map* map;
	Ship** ships;
	ShipCreator* shipCreator;
public:
	Game();
	virtual ~Game();
};

#endif
