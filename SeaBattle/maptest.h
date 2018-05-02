#ifndef __MAPTEST
#define __MAPTEST

#include "defs.h"
#include "map.h"

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
		ui8 rndX = Random(9);
		ui8 rndY = Random(9);
		(*expectMap)[rndX][rndY] = bomb;
		actualMap->fire(rndX, rndY);
		EXPECT_EQ(*expectMap, *actualMap);
		delete actualMap;
		delete expectMap;
	}
}

#endif
