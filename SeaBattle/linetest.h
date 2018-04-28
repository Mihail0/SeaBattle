#ifndef __LINETEST
#define __LINETEST

#include "defs.h"

class LineTest :
	public testing::Test {
private:
protected:
	Line* line;
public:
	LineTest();
	virtual ~LineTest();
};

#endif
