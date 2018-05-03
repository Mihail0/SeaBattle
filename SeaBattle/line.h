#ifndef __LINE
#define __LINE

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
		ui8 rnd = Random(100);
		if (rnd > 9) {
			EXPECT_THROW(line->fire(rnd), std::out_of_range);
		}
		else {
			line->fire(rnd);
			EXPECT_EQ(expected, (*line)[rnd]);
		}
	}
}

class Line {
private:
protected:
	ui8* elements;
public:
	virtual void fire(const ui8 &);
	bool operator==(const Line &) const;
	bool operator!=(const Line &) const;
	ui8& operator[](const ui8 &);
	Line();
	virtual ~Line();
};

#endif
