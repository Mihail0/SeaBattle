#ifndef __SHIP
#define __SHIP

#include "defs.h"

class Ship {
	friend class ShipTest;
	friend class ShipCreator;
private:
protected:
	ui8 x, y;
	ui8* count;
public:
	bool operator==(const Ship &) const;
	bool operator!=(const Ship &) const;
	Ship();
	Ship(const ui8 &, const ui8 &);
	Ship(const ui8 &, const ui8 &, ui8*);
	virtual ~Ship();
};

#endif
