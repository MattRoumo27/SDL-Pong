#include "ball.h"
#include <SDL.h>

Ball::Ball(int _x, int _y) : GameObject(_x, _y)
{
	xSpeed = RIGHT_DIRECTION * INITIAL_BALL_SPEED;
	ySpeed = 0;
}

void Ball::update()
{
	setY(getY() + ySpeed);
	setX(getX() + xSpeed);
}

void Ball::draw(SDL_Renderer* renderer) const
{
	SDL_Rect ballRectangle = { getX(), getY(), SIDE_LENGTH, SIDE_LENGTH };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &ballRectangle);
}
