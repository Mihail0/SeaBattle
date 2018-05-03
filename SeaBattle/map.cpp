#include "map.h"

/**
* Fired at the points around the target ship
* @param x - x-coordinate of the target ship
* @param y - y-coordinate of the target ship
* @note x & y should be within the MAPSIZE
* @note point should be part of the ship
*/
void Map::explode(const ui8 &x, const ui8 &y) {
	if (!(x < 10 && y < 10)) throw std::out_of_range("Array index is out of range");
	if (container[x][y] != crash) throw std::bad_alloc();
	//Searching for the first point of ship
	ui8 X = x;
	ui8 Y = y;
	while (X) {
		if (container[X - 1][Y] != crash) break;
		else X--;
	}
	while (Y) {
		if (container[X][Y - 1] != crash) break;
		else Y--;
	}
	//Explosion
	while (X < MAPSIZE) {
		fireAround(X, Y);
		if (container[X + 1][Y] != crash) break;
		else X++;
	}
	while (Y < MAPSIZE) {
		fireAround(X, Y);
		if (container[X][Y + 1] != crash) break;
		else Y++;
	}
}

/**
* Fired at the target cell of map
* @param x - x-coordinate of the target
* @param y - y-coordinate of the target
* @note x & y should be within the MAPSIZE
*/
void Map::fire(const ui8 &x, const ui8 &y) {
	if (x < 10 && y < 10) {
		switch (container[x][y]) {
		case water:
			container[x][y] = bomb;
			break;
		case ship:
			container[x][y] = crash;
			break;
		default:
			break;
		}
	}
	else {
		throw std::out_of_range("Array index is out of range");
	}
}

/**
* Fired at the target cell of map
* @param x - x-coordinate of the target
* @param y - y-coordinate of the target
* @param ships - An 2d array of pointers to ships
* @param lengths - An array of lengths
* @note x & y should be within the MAPSIZE
* @note This function additionally destroy the ship that was hit
*/
void Map::fire(const ui8 &x, const ui8 &y, Ship*** &ships, ui8* &lengths) {
	fire(x, y);
	for (ui8 i = 0; i < MAXSHIPS; i++) {
		for (ui8 j = 0; j < lengths[i]; j++) {
			if (!ships[i][j]) continue;
			if ((x == ships[i][j]->x) && (y == ships[i][j]->y)) {
				bool rem = false;
				if (ships[i][j]->getCount() == 1) {
					rem = true;
				}
				delete ships[i][j];
				ships[i][j] = NULL;
				if (rem) {
					delete[] ships[i];
					ships[i] = NULL;
					lengths[i] = 0;
					explode(x, y);
				}
			}
		}
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
