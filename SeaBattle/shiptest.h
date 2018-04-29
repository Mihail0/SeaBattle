#ifndef __SHIPTEST
#define __SHIPTEST

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

#endif
