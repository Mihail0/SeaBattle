#ifndef __DEFS
#define __DEFS
#include <string>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <algorithm>
#include <gtest/gtest.h>

#define ui8 unsigned __int8
#define MAPSIZE 10
#define Random(x) (rand() % static_cast<ui8>(x))

enum States {
	water,
	bomb,
	ship,
	crash
};

enum Directions {
	horizontal,
	vertical
};

#endif
