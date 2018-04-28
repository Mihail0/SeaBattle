#ifndef __LINE
#define __LINE

#include "defs.h"

class Line {
private:
protected:
	ui8* elements;
public:
	ui8 operator[](const ui8 &) const;
	Line();
	virtual ~Line();
};

#endif
