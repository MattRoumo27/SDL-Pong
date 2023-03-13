#include "paddle.h"
#include <SDL.h>

Paddle::Paddle(int _x, int _y) : GameObject(_x, _y)
{ }

void Paddle::update()
{
}

void Paddle::draw(SDL_Renderer* renderer) const
{
	SDL_Rect paddleRectangle = { getX(), getY(), PADDLE_WIDTH, PADDLE_HEIGHT };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &paddleRectangle);
}