#include "playerinputcomponent.h"
#include "paddle.h"
#include <SDL.h>

PlayerInputComponent::PlayerInputComponent()
{ }

void PlayerInputComponent::handleInput(Paddle* player, SDL_Event* sdlEvent)
{
	if (sdlEvent->type == SDL_KEYDOWN && sdlEvent->key.repeat == 0)
	{
		switch (sdlEvent->key.keysym.sym)
		{
			case SDLK_w:
			case SDLK_UP:
				player->setY(player->getY() - Paddle::MOVE_SPEED);
				break;
			case SDLK_s:
			case SDLK_DOWN:
				player->setY(player->getY() + Paddle::MOVE_SPEED);
				break;
		}
	}
}
