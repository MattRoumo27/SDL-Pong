#include "playerinputcomponent.h"
#include "paddle.h"
#include <SDL.h>

PlayerInputComponent::PlayerInputComponent()
{ }

void PlayerInputComponent::handleInput(Paddle* player, double deltaTime)
{
	const Uint8* keyState = SDL_GetKeyboardState(nullptr);

	if (keyState[SDL_SCANCODE_W])
	{
		player->position.y -= Paddle::MOVE_SPEED * (float)deltaTime;

	}
	else if (keyState[SDL_SCANCODE_S])
	{
		player->position.y += Paddle::MOVE_SPEED * (float)deltaTime;
	}
}
