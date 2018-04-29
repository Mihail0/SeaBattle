#include "line.h"

void Line::fire(const ui8 &index) {
	//todo method is not complete
	if (index < 3) {
		elements[index] = bomb;
	}
	else {
		throw 0;
	}
}

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
