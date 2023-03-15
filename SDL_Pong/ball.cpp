#include "ball.h"
#include "paddle.h"
#include "game.h"
#include <SDL.h>
#include <cmath>
#include <cstdlib>

const float Ball::SIDE_LENGTH = 10;

Ball::Ball(float _x, float _y, Paddle* leftPaddle, Paddle* rightPaddle) : GameObject(_x, _y), leftPaddle(leftPaddle), rightPaddle(rightPaddle)
{
	setInitialSpeed();
}

void Ball::update(double deltaTime)
{
	setY(getY() + ySpeed * (float)deltaTime);
	setX(getX() + xSpeed * (float)deltaTime);

	if (getY() < 0)
	{
		setY(0);
		ySpeed *= -1;
	}
	else if ((getY() + SIDE_LENGTH) > Game::WINDOW_HEIGHT)
	{
		setY(Game::WINDOW_HEIGHT - SIDE_LENGTH);
		ySpeed *= -1;
	}
	else if (getX() < 0 || (getX() + SIDE_LENGTH) > Game::WINDOW_WIDTH)
	{
		reset();
	}

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
	if (xSpeed > 0)
	{
		xSpeed *= -1 * SPEED_MULTIPLIER;
		setX(paddleHit->getX() - SIDE_LENGTH);
	}
	else
	{
		xSpeed *= -1 * SPEED_MULTIPLIER;
		setX(paddleHit->getX() + Paddle::PADDLE_WIDTH + SIDE_LENGTH);
	}
}

void Ball::reset()
{
	setX((float)Game::WINDOW_WIDTH / 2);
	setY((float)Game::WINDOW_HEIGHT / 2);

	setInitialSpeed();
}

void Ball::setInitialSpeed()
{
	xSpeed = RIGHT_DIRECTION * INITIAL_BALL_SPEED;
	ySpeed = (-3 + (rand() % 3)) * (INITIAL_BALL_SPEED / 2);
}

void Ball::draw(SDL_Renderer* renderer) const
{
	SDL_Rect ballRectangle = { getX(), getY(), SIDE_LENGTH, SIDE_LENGTH };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &ballRectangle);
}
