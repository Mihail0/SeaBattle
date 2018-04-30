#include "shipcreator.h"

Ship** ShipCreator::create(Map* &map, const ui8 &direction, const ui8 &x, const ui8 &y, const ui8 &length) {
	//todo method is not complete
	Ship** ships = new Ship*[1];
	ships[0] = new Ship(0, 0);
	(*map)[0][0] = ship;
	return ships;
}

ShipCreator::ShipCreator() {

}

ShipCreator::~ShipCreator() {

}
