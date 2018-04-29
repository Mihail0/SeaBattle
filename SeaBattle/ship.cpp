#include "ship.h"

Ship::Ship() {
	x = 0;
	y = 0;
	count = NULL;
}

Ship::~Ship() {
	if (count) {
		(*count)--;
		if (!(*count)) delete count;
	}
}
