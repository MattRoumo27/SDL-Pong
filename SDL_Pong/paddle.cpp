#include "paddle.h"
#include "game.h"
#include <SDL.h>

Paddle::Paddle(int _x, int _y) : GameObject(_x, _y)
{ }

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

int Paddle::getBottomYCoordinate() const
{
	return getY() + PADDLE_HEIGHT;
}

void Paddle::draw(SDL_Renderer* renderer) const
{
	SDL_Rect paddleRectangle = { getX(), getY(), PADDLE_WIDTH, PADDLE_HEIGHT };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &paddleRectangle);
}
