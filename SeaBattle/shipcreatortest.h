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
		ui8 rndLength = Random(100);	//Random length of ship
		ui8 rndX = Random(100);			//Random x-coordinate
		ui8 rndY = Random(100);			//Random y-coordinate
		ui8 rndDirection = Random(2);	//Random direction

		//Initialize actual variables
		Map* actualMap = new Map();

		bool cond = false;
		rndDirection == horizontal ? 
			cond = rndX + rndLength <= MAPSIZE : 
			cond = rndY + rndLength <= MAPSIZE ;
		if (!(rndLength > 0 && cond)) {
			EXPECT_THROW(shipCreator->create(actualMap, rndDirection, rndX, rndY, rndLength), std::out_of_range);
			delete actualMap;
			continue;
		}

		Ship** actualShips = shipCreator->create(actualMap, rndDirection, rndX, rndY, rndLength);

		//Initialize expected variables
		Map* expectedMap = new Map();
		Ship** expectedShips = new Ship*[rndLength];
		ui8* counter = new ui8();
		*counter = rndLength;
		for (ui8 j = 0; j < rndLength; j++) {
			if (rndDirection == horizontal) {
				expectedShips[j] = new Ship(rndX + j, rndY, counter);
				(*expectedMap)[rndX + j][rndY] = ship;
			}
			else {
				expectedShips[j] = new Ship(rndX, rndY + j, counter);
				(*expectedMap)[rndX][rndY + j] = ship;
			}
		}

		//Comparison
		EXPECT_EQ(*expectedMap, *actualMap);
		for (ui8 j = 0; j < rndLength; j++) {
			EXPECT_EQ((*expectedShips[j]), (*actualShips[j]));
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
