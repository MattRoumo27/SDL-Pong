#include "game.h"
#include "stdlib.h"
#include "time.h"

int main(int argc, char* args[])
{
	srand(time(nullptr));

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