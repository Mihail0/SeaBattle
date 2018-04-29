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

TEST_F(LineTest, LineFireAtXTest) {
	ui8 expected = bomb;
	for (ui8 i = 0; i < 100; i++) {
		ui8 rand = Random(100);
		if (rand > 9) {
			try {
				line->fire(rand);
			}
			catch (ui8 exc) {
				EXPECT_EQ(0, exc);
			}
		}
		else {
			line->fire(rand);
			EXPECT_EQ(expected, (*line)[rand]);
		}
	}
}

#endif
