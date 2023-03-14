#include "playerinputcomponent.h"
#include "player.h"
#include <SDL.h>

PlayerInputComponent::PlayerInputComponent()
{ }

void PlayerInputComponent::handleInput(Player* player, SDL_Event* sdlEvent)
{
	if (sdlEvent->type == SDL_KEYDOWN && sdlEvent->key.repeat == 0)
	{
		switch (sdlEvent->key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_UP:
			player->setY(player->getY() - Player::MOVE_SPEED);
			break;
		case SDLK_s:
		case SDLK_DOWN:
			player->setY(player->getY() + Player::MOVE_SPEED);
			break;
		}
	}
}
