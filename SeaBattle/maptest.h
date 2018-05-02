#ifndef __MAPTEST
#define __MAPTEST

#include "defs.h"
#include "ship.h"
#include "map.h"
#include "shipcreator.h"

class MapTest :
	public testing::Test {
private:
protected:
	Map* map;
public:
	MapTest();
	virtual ~MapTest();
};

TEST_F(MapTest, MapCreationTest) {
	ASSERT_TRUE(map != NULL);
}

TEST_F(MapTest, MapInitializationTest) {
	ui8 expected = water;
	for (ui8 i = 0; i < MAPSIZE; i++) {
		for (ui8 j = 0; j < MAPSIZE; j++) {
			ASSERT_EQ(expected, (*map)[i][j]);
		}
	}
}

TEST_F(MapTest, MapFireAtX0Test) {
	ui8 expected = bomb;
	for (ui8 i = 0; i < 100; i++) {
		ui8 rnd = Random(100);
		if (rnd > 9) {
			EXPECT_THROW(map->fire(rnd, 0), std::out_of_range);
		}
		else {
			map->fire(rnd, 0);
			EXPECT_EQ(expected, (*map)[rnd][0]);
		}
	}
}

TEST_F(MapTest, MapFireAtXYTest) {
	ui8 expected = bomb;
	for (ui8 i = 0; i < 100; i++) {
		ui8 rndX = Random(100);
		ui8 rndY = Random(100);
		if (rndX > 9 || rndY > 9) {
			EXPECT_THROW(map->fire(rndX, rndY), std::out_of_range);
		}
		else {
			map->fire(rndX, rndY);
			EXPECT_EQ(expected, (*map)[rndX][rndY]);
		}
	}
}

TEST_F(MapTest, MapFireAtMapTest) {
	for (ui8 i = 0; i < 100; i++) {
		Map* expectMap = new Map();
		Map* actualMap = new Map();
		EXPECT_EQ(*expectMap, *actualMap);
		ui8 rndX = Random(10);
		ui8 rndY = Random(10);
		(*expectMap)[rndX][rndY] = bomb;
		actualMap->fire(rndX, rndY);
		EXPECT_EQ(*expectMap, *actualMap);
		delete actualMap;
		delete expectMap;
	}
}

TEST_F(MapTest, MapFireAtShipTest) {
	for (ui8 i = 0; i < 100; i++) {
		Map* expectMap = new Map();
		Map* actualMap = new Map();
		Ship** expectShip = NULL;
		Ship** actualShip = NULL;

		//Initialization
		//Fire coordinates
		ui8 fireX = Random(10);
		ui8 fireY = Random(10);

		//Ship coordinates
		ui8 shipX = Random(10);
		ui8 shipY = Random(10);
		ui8 shipD = Random(2);
		ui8 shipL = 0;
		shipD == horizontal ?
			shipL = 1 + Random(10 - shipX) :
			shipL = 1 + Random(10 - shipY) ;

		//Expected
		(*expectMap)[fireX][fireY] = bomb;
		ui8* c = new ui8(); *c = shipL;
		expectShip = new Ship*[shipL];
		for (ui8 k = 0, X = shipX, Y = shipY; k < shipL; k++) {
			expectShip[k] = new Ship(X, Y, c);
			if (!(X == fireX && Y == fireY)) {
				//Didn't hit
				(*expectMap)[X][Y] = ship;
			}
			else {
				//Hit
				(*expectMap)[X][Y] = crash;
				delete expectShip[k];
				expectShip[k] = NULL;
			}
			shipD == horizontal ? X++ : Y++;
		}

		//Actual
		ShipCreator* shipCreator = new ShipCreator();
		actualShip = shipCreator->create(actualMap, shipD, shipX, shipY, shipL);
		actualMap->fire(fireX, fireY);

		//Comparison
		EXPECT_EQ((*expectMap), (*actualMap));
		for (ui8 j = 0; j < shipL; j++) {
			if (!expectShip[j]) EXPECT_TRUE(actualShip[j] == NULL);
			else EXPECT_EQ((*expectShip[j]), (*actualShip[j]));
		}

		delete shipCreator;
		for (ui8 j = 0; j < shipL; j++) {
			delete actualShip[j];
			delete expectShip[j];
		}
		delete[] actualShip;
		delete[] expectShip;
		delete actualMap;
		delete expectMap;
	}
}

#endif
