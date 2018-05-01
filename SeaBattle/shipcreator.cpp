#include "shipcreator.h"

Ship** ShipCreator::create(Map* &map, const ui8 &direction, const ui8 &x, const ui8 &y, const ui8 &length) {
	//todo method is not complete
	if (!length) throw std::out_of_range("Array index is out of range");
	Ship** ships = new Ship*[length];
	for (ui8 i = 0; i < length; i++) {
		ships[i] = NULL;
	}
	ui8* counter = new ui8();
	*counter = length;
	ui8 error = 0;
	for (ui8 i = 0, X = x, Y = y; !error && (i < length); i++) {
		if (X >= MAPSIZE || Y >= MAPSIZE) error = 1;
		direction == horizontal ? X++ : Y++;
	}
	for (ui8 i = 0, X = x, Y = y; !error && (i < length); i++) {
		ui8 n = 0; if (X) n = X - 1;
		ui8 m = 0; if (Y) m = Y - 1;
		ui8 p = X + 1; if (p > (MAPSIZE - 1)) p = MAPSIZE - 1;
		ui8 q = Y + 1; if (q > (MAPSIZE - 1)) q = MAPSIZE - 1;
		for (ui8 r = n; !error && (r <= p); r++) {
			for (ui8 s = m; !error && (s <= q); s++) {
				if ((*map)[r][s] == ship) {
					error = 2;
				}
			}
		}
		direction == horizontal ? X++ : Y++;
	}
	if (!error) {
		for (ui8 i = 0, X = x, Y = y; i < length; i++) {
			ships[i] = new Ship(X, Y, counter);
			(*map)[X][Y] = ship;
			direction == horizontal ? X++ : Y++;
		}
	}
	else {
		for (ui8 j = 0; j < length; j++) {
			delete ships[j];
		}
		delete[] ships;
		if (counter) delete counter;
		switch (error) {
		case 1:
			throw std::out_of_range("Array index is out of range");
		case 2:
			throw std::bad_alloc();
		default:
			break;
		}
	}
	return ships;
}

ShipCreator::ShipCreator() {

}

ShipCreator::~ShipCreator() {

}
