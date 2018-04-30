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
	for (ui8 i = 0; i < length; i++) {
		if (i >= MAPSIZE) {
			for (ui8 j = 0; j < length; j++) {
				delete ships[j];
			}
			delete[] ships;
			if (counter) delete counter;
			throw std::out_of_range("Array index is out of range");
		}
		ships[i] = new Ship(i, 0, counter);
		(*map)[i][0] = ship;
	}
	return ships;
}

ShipCreator::ShipCreator() {

}

ShipCreator::~ShipCreator() {

}
