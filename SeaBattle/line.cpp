#include "line.h"

ui8 Line::operator[](const ui8 &index) const {
	return elements[index];
}

Line::Line() {
	for (ui8 i = 0; i < MAPSIZE; i++) {
		elements[i] = water;
	}
}

Line::~Line() {
	delete[] elements;
}
