#include "game.h"

GameTest::GameTest() {
	game = new Game();
}

GameTest::~GameTest() {
	delete game;
}

Game::Game() {
	map = new Map();
	shipCreator = new ShipCreator();
	ships = shipCreator->create(map, 0, 0, 0, 1);
}

Game::~Game() {
	delete ships[0];
	delete[] ships;
	delete shipCreator;
	delete map;
}
