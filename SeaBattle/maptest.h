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

TEST_F(MapTest, MapFireAt00TEST) {
	ui8 expected = bomb;
	map->fire(0, 0);
	EXPECT_EQ(expected, (*map)[0][0]);
}

TEST_F(MapTest, MapFireAt01TEST) {
	ui8 expected = bomb;
	map->fire(0, 1);
	EXPECT_EQ(expected, (*map)[0][1]);
}

#endif
