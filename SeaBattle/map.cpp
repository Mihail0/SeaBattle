#include "map.h"

/**
* Fired at the target cell of map
* @param x - x-coordinate of the target
* @param y - y-coordinate of the target
* @note x & y should be less than the mapsize
*/
void Map::fire(const ui8 &x, const ui8 &y) {
	if (x < 10 && y < 10) {
		container[x][y] = bomb;
	}
	else {
		throw std::out_of_range("Array index is out of range");
	}
}

bool Map::operator==(const Map &map) const {
	for (ui8 i = 0; i < MAPSIZE; i++) {
		if (container[i] != map.container[i]) return false;
	}
	return true;
}

bool Map::operator!=(const Map &map) const {
	return !operator==(map);
}

Line& Map::operator[](const ui8 &index) {
	return container[index];
}

Map::Map() {
	container = new Line[MAPSIZE];
}

Map::~Map() {
	delete[] container;
}
