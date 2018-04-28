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

TEST_F(GameTest, GameCreationTest) {
	ASSERT_NE(NULL, game);
}

#endif
