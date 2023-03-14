#include <stdio.h>
#include <SDL.h>
#include "game.h"
#include "player.h"

int main(int argc, char* args[])
{
	Game* game = new Game();

	bool success = game->initializeSDLSystems();
	if (!success)
	{
		delete game;
		return 0;
	}

	game->gameLoop();

	delete game;
	return 0;
}