#ifndef __MAP
#define __MAP

#include "defs.h"

class Map {
private:
protected:
	Line* container;
public:
	Line& operator[](const ui8 &) const;
	Map();
	virtual ~Map();
};

#endif
