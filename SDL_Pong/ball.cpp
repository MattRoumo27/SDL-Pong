#include "ball.h"
#include "paddle.h"
#include <SDL.h>
#include <cmath>

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
	if (hasHitPaddle(leftPaddle))
	{
		paddleHit = leftPaddle;
	}
	else if (hasHitPaddle(rightPaddle))
	{
		paddleHit = rightPaddle;
	}

	if (paddleHit != nullptr)
	{
		handlePaddleHit(paddleHit);
	}
}

bool Ball::hasHitPaddle(Paddle* paddle)
{
	return getX() < paddle->getX() + Paddle::PADDLE_WIDTH &&
		getX() + SIDE_LENGTH > paddle->getX() &&
		getY() < paddle->getY() + Paddle::PADDLE_HEIGHT &&
		getY() + SIDE_LENGTH > paddle->getY();
}

void Ball::handlePaddleHit(Paddle* paddleHit)
{
	float directionVectorY = getWhereBallHitPaddle(paddleHit);
	float directionVectorX = 1;

	float directionVectorLength = sqrt(pow(directionVectorX, 2) + pow(directionVectorY, 2));
	directionVectorX /= directionVectorLength;
	directionVectorY /= directionVectorLength;

	if (xSpeed > 0)
	{
		xSpeed *= -1;
		setX(paddleHit->getX() - SIDE_LENGTH);
	}
	else
	{
		xSpeed *= -1;
		setX(paddleHit->getX() + Paddle::PADDLE_WIDTH);
	}

	xSpeed *= directionVectorX * SPEED_MULTIPLIER;

	if (ySpeed != 0)
	{
		ySpeed *= directionVectorY * SPEED_MULTIPLIER;
	}
	else
	{
		ySpeed = directionVectorY * SPEED_MULTIPLIER;
	}
}

float Ball::getWhereBallHitPaddle(Paddle* paddleHit)
{
	float difference = (getY() + SIDE_LENGTH / 2) - (paddleHit->getY() + Paddle::PADDLE_HEIGHT / 2);

	return difference / Paddle::PADDLE_HEIGHT;
}

void Ball::draw(SDL_Renderer* renderer) const
{
	SDL_Rect ballRectangle = { getX(), getY(), SIDE_LENGTH, SIDE_LENGTH };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &ballRectangle);
}
