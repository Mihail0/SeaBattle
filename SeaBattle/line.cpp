#include "line.h"

ui8& Line::operator[](const ui8 &index) {
	return elements[index];
}

Line::Line() {
	elements = new ui8[MAPSIZE];
	for (ui8 i = 0; i < MAPSIZE; i++) {
		elements[i] = water;
	}
}

Line::~Line() {
	delete[] elements;
}
