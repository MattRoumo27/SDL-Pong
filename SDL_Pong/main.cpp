#include <stdio.h>
#include <SDL.h>
#include "game.h"
#include "player.h"

int main(int argc, char* args[])
{
	Game *game = new Game();

	bool success = game->initializeSDLSystems();
	if (!success)
	{
		delete game;
		return 0;
	}

	bool quitGame = false;

	SDL_Event sdlEvent;
	Player* player;

	while (!quitGame)
	{
		while (SDL_PollEvent(&sdlEvent) != 0)
		{
			if (sdlEvent.type == SDL_QUIT)
			{
				quitGame = true;
			}
			else if (sdlEvent.type == SDL_KEYDOWN)
			{
				player = game->getPlayer();

				switch (sdlEvent.key.keysym.sym)
				{
					case SDLK_w:
					case SDLK_UP:
						player->setY(player->getY() - 5);
						break;
					case SDLK_s:
					case SDLK_DOWN:
						player->setY(player->getY() + 5);
						break;
				}
			}
		}

		game->update();
		game->draw();
	}

	delete game;
	return 0;
}