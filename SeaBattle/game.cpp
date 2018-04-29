#include "game.h"

Game::Game() {
	map = new Map();
}

Game::~Game() {
	delete map;
}
