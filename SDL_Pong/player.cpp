#include "player.h"
#include "playerinputcomponent.h"
#include <SDL.h>

Player::Player(float _x, float _y, PlayerInputComponent* inputComponent): Paddle(_x, _y), inputComponent(inputComponent)
{ }

Player::~Player()
{
	delete inputComponent;
}

void Player::handleInput(SDL_Event* sdlEvent)
{
	inputComponent->handleInput(this, sdlEvent);
}

void Player::update()
{ 
	Paddle::update();
}

