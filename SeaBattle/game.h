#ifndef __GAME
#define __GAME

#include "defs.h"
#include "map.h"
#include "ship.h"
#include "shipcreator.h"

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

TEST_F(GameTest, GameMapInitTest) {
	ASSERT_TRUE(game->map != NULL);
}

TEST_F(GameTest, GameShipCreatorInitTest) {
	ASSERT_TRUE(game->shipCreator != NULL);
}

TEST_F(GameTest, GameShipsInitTest) {
	ASSERT_TRUE(game->ships != NULL);
}

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
