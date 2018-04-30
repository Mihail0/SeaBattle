#ifndef __SHIPCREATORTEST
#define __SHIPCREATORTEST

#include "defs.h"
#include "ship.h"
#include "shipcreator.h"
#include "map.h"

class ShipCreatorTest :
	public testing::Test {
private:
protected:
	ShipCreator* shipCreator;
public:
	ShipCreatorTest();
	virtual ~ShipCreatorTest();
};

TEST_F(ShipCreatorTest, ShipCreatorCreationTest) {
	ASSERT_TRUE(shipCreator != NULL);
}

TEST_F(ShipCreatorTest, ShipCreatorCreateTest) {
	for (ui8 i = 0; i < 100; i++) {
		//Random length of ship
		ui8 rndLength = Random(100);

		//Initialize actual variables
		Map* actualMap = new Map();
		Ship** actualShips = shipCreator->create(actualMap, horizontal, 0, 0, rndLength);

		//Initialize expected variables
		Map* expectedMap = new Map();
		Ship** expectedShips = new Ship*[rndLength];
		ui8* counter = new ui8();
		*counter = rndLength;
		for (ui8 j = 0; j < rndLength; j++) {
			expectedShips[j] = new Ship(j, 0, counter);
			(*expectedMap)[j][0] = ship;
		}

		//Comparison
		EXPECT_EQ(*expectedMap, *actualMap);
		for (ui8 j = 0; j < rndLength; j++) {
			EXPECT_EQ((*expectedShips)[j], (*actualShips)[j]);
		}

		//Final cleansing
		for (ui8 j = 0; j < rndLength; j++) {
			delete actualShips[j];
			delete expectedShips[j];
		}
		delete[] actualShips;
		delete[] expectedShips;
		delete actualMap;
		delete expectedMap;
	}
}

#endif
