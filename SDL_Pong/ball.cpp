#include "ball.h"
#include "paddle.h"
#include <SDL.h>

Ball::Ball(float _x, float _y, Paddle* leftPaddle, Paddle* rightPaddle) : GameObject(_x, _y), leftPaddle(leftPaddle), rightPaddle(rightPaddle)
{
	xSpeed = RIGHT_DIRECTION * INITIAL_BALL_SPEED;
	ySpeed = 0;
}

void Ball::update()
{
	setY(getY() + ySpeed);
	setX(getX() + xSpeed);

	// Check for collisions with the paddles
	Paddle* paddleHit = nullptr;
	if (haveObjectsCollided(leftPaddle))
	{
		paddleHit = leftPaddle;
	}
	else if (haveObjectsCollided(rightPaddle))
	{
		paddleHit = rightPaddle;
	}

	if (paddleHit != nullptr)
	{
		handlePaddleHit(paddleHit);
	}
}

void Ball::handlePaddleHit(Paddle* paddleHit)
{

}

void Ball::draw(SDL_Renderer* renderer) const
{
	SDL_Rect ballRectangle = { getX(), getY(), SIDE_LENGTH, SIDE_LENGTH };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &ballRectangle);
}
