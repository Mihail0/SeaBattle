#include "map.h"

void Map::fire(const ui8 &x, const ui8 &y) {
	//todo method is not complete
	if (x < 10) {
		container[x][0] = bomb;
	}
	else {
		throw std::out_of_range("Array index is out of range");
	}
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
