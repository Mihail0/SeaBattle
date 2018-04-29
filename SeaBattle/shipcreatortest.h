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
	//Expected variables
	Map* expectedMap = new Map();
	Ship** expectedShips = new Ship*[1];
	expectedShips[0] = new Ship(0, 0);
	
	//Initialization
	(*expectedMap)[0][0] = ship;

	//Actual variables
	Map* actualMap = new Map();
	Ship** actualShips = shipCreator->create(actualMap, horizontal, 0, 0, 1);

	//Comparison
	EXPECT_EQ(expectedMap, actualMap);
	EXPECT_EQ(expectedShips[0], actualShips[0]);

	//Final cleansing
	delete actualShips[0];
	delete[] actualShips;
	delete actualMap;
	delete expectedShips[0];
	delete[] expectedShips;
	delete expectedMap;
}

#endif
