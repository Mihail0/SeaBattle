#ifndef __SHIP
#define __SHIP

#include "defs.h"

class ShipTest :
	public testing::Test {
private:
protected:
	Ship* ship;
public:
	ShipTest();
	virtual ~ShipTest();
};

TEST_F(ShipTest, ShipCreationTest) {
	ASSERT_TRUE(ship != NULL);
}

class Ship {
	friend class ShipTest;
	friend class ShipCreator;
private:
protected:
	ui8* count;
	ui8 x, y;
public:
	ui8 getX() const;
	ui8 getY() const;
	ui8 getCount() const;
	bool operator==(const Ship &) const;
	bool operator!=(const Ship &) const;
	Ship();
	Ship(const ui8 &, const ui8 &);
	Ship(const ui8 &, const ui8 &, ui8*);
	virtual ~Ship();
};

#endif
