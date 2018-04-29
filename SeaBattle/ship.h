#ifndef __SHIP
#define __SHIP

#include "defs.h"

class Ship {
	friend class ShipTest;
private:
protected:
	ui8 x, y;
	ui8* count;
public:
	Ship();
	virtual ~Ship();
};

#endif
