#ifndef __MAP
#define __MAP

#include "defs.h"
#include "line.h"

class Map {
private:
protected:
	Line* container;
public:
	Line& operator[](const ui8 &);
	Map();
	virtual ~Map();
};

#endif
