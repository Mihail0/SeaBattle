#include "map.h"

Line& Map::operator[](const ui8 &index) const {

}

Map::Map() {
	container = new Line[MAPSIZE];
}

Map::~Map() {
	delete[] container;
}
