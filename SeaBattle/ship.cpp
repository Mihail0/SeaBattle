#include "ship.h"

Ship::Ship() {
	x = 0;
	y = 0;
	count = NULL;
}

Ship::Ship(const ui8 &x, const ui8 &y) : Ship() {
	//todo this constructor is not complete 
}

Ship::~Ship() {
	if (count) {
		(*count)--;
		if (!(*count)) delete count;
	}
}
