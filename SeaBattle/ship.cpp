#include "ship.h"

bool Ship::operator==(const Ship &ship) const {
	if (x != ship.x) return false;
	if (y != ship.y) return false;
	if (count != ship.count) return false;
	return true;
}

bool Ship::operator!=(const Ship &ship) const {
	return !operator==(ship);
}

Ship::Ship() {
	x = 0;
	y = 0;
	count = NULL;
}

Ship::Ship(const ui8 &X, const ui8 &Y) : Ship() {
	//todo this constructor is not complete 
}

Ship::Ship(const ui8 &X, const ui8 &Y, ui8* counter) : Ship(X, Y) {
	count = counter;
}

Ship::~Ship() {
	if (count) {
		(*count)--;
		if (!(*count)) delete count;
	}
}
