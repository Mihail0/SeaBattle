#ifndef __MAP
#define __MAP

#include "defs.h"
#include "line.h"

class Map {
private:
protected:
	Line* container;
public:
	virtual void fire(const ui8 &, const ui8 &);
	Line& operator[](const ui8 &);
	Map();
	virtual ~Map();
};

#endif
