#ifndef __GAMETEST
#define __GAMETEST

#include "defs.h"

class GameTest :
	public testing::Test {
private:
protected:
	Game* game;
public:
	GameTest();
	virtual ~GameTest();
};

#endif
