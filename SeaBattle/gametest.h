#ifndef __GAMETEST
#define __GAMETEST

#include "defs.h"
#include "game.h"

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
	ASSERT_TRUE(game != NULL);
}

#endif
