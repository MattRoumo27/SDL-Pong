#include "paddle.h"
#include "game.h"
#include "inputcomponent.h"
#include <SDL.h>

const float Paddle::PADDLE_WIDTH = 10;
const float Paddle::PADDLE_HEIGHT = 60;
const float Paddle::PADDLE_OFFSET = 50;

Paddle::Paddle(float _x, float _y) : GameObject(_x, _y), inputComponent(nullptr)
{ }

Paddle::Paddle(float _x, float _y, class InputComponent* inputComponent) : GameObject(_x, _y), inputComponent(inputComponent)
{ }

Paddle::~Paddle()
{
	delete inputComponent;
}

void Paddle::update()
{
	if (getY() <= 0)
	{
		setY(0);
	}
	else if (getBottomYCoordinate() >= Game::WINDOW_HEIGHT)
	{
		setY(Game::WINDOW_HEIGHT - PADDLE_HEIGHT);
	}
}

void Paddle::setInputComponent(InputComponent* _inputComponent)
{
	inputComponent = _inputComponent;
}

void Paddle::handleInput(SDL_Event* sdlEvent)
{
	inputComponent->handleInput(this, sdlEvent);
}

float Paddle::getBottomYCoordinate() const
{
	return getY() + PADDLE_HEIGHT;
}

void Paddle::draw(SDL_Renderer* renderer) const
{
	SDL_Rect paddleRectangle = { getX(), getY(), PADDLE_WIDTH, PADDLE_HEIGHT };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &paddleRectangle);
}

