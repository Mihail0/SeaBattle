#ifndef __SHIPCREATORTEST
#define __SHIPCREATORTEST

#include "defs.h"
#include "shipcreator.h"

class ShipCreatorTest :
	public testing::Test {
private:
protected:
	ShipCreator* shipCreator;
public:
	ShipCreatorTest();
	virtual ~ShipCreatorTest();
};

#endif
