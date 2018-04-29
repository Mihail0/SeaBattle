#ifndef __LINETEST
#define __LINETEST

#include "defs.h"
#include "line.h"

class LineTest :
	public testing::Test {
private:
protected:
	Line* line;
public:
	LineTest();
	virtual ~LineTest();
};

TEST_F(LineTest, LineCreationTest) {
	ASSERT_TRUE(line != NULL);
}

TEST_F(LineTest, LineInitializationTest) {
	ui8 expected = water;
	for (ui8 i = 0; i < MAPSIZE; i++) {
		ASSERT_EQ(expected, (*line)[i]);
	}
}

TEST_F(LineTest, LineFireAt0Test) {
	ui8 expected = bomb;
	EXPECT_EQ(expected, (*line)[0]);
}

TEST_F(LineTest, LineFireAt1Test) {
	ui8 expected = bomb;
	EXPECT_EQ(expected, (*line)[1]);
}

#endif
