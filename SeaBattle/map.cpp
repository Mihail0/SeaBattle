#include "map.h"

Line& Map::operator[](const ui8 &index) {

}

Map::Map() {
	container = new Line[MAPSIZE];
}

Map::~Map() {
	delete[] container;
}
