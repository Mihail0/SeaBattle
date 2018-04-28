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

#endif
