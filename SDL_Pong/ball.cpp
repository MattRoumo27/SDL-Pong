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

void Ball::setInitialSpeed()
{
	speedVector.x = RIGHT_DIRECTION * INITIAL_SPEED;
	speedVector.y = (-3 + (rand() % 3)) * (INITIAL_SPEED / 2);
}

void Ball::update(double deltaTime)
{
	position.x += speedVector.x * (float)deltaTime;
	position.y += speedVector.y * (float)deltaTime;

	if (position.y < 0)
	{
		position.y = 0;
		speedVector.y *= -1;
	}
	else if ((position.y + SIDE_LENGTH) > Game::WINDOW_HEIGHT)
	{
		position.y = Game::WINDOW_HEIGHT - SIDE_LENGTH;
		speedVector.y *= -1;
	}
	else if (position.x < 0 || (position.x + SIDE_LENGTH) > Game::WINDOW_WIDTH)
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
	return position.x < paddle->position.x + Paddle::PADDLE_WIDTH &&
		position.x + SIDE_LENGTH > paddle->position.x &&
		position.y < paddle->position.y + Paddle::PADDLE_HEIGHT &&
		position.y + SIDE_LENGTH > paddle->position.y;
}

void Ball::handlePaddleHit(Paddle* paddleHit)
{
	if (speedVector.x > 0)
	{
		if (abs(speedVector.x) > MAXIMUM_SPEED)
		{
			speedVector.x *= -1;
		}
		else
		{
			speedVector.x *= -1 * SPEED_MULTIPLIER;
		}
		position.x = paddleHit->position.x - SIDE_LENGTH;
	}
	else
	{
		if (abs(speedVector.x) > MAXIMUM_SPEED)
		{
			speedVector.x *= -1;
		}
		else
		{
			speedVector.x *= -1 * SPEED_MULTIPLIER;
		}
		position.x = paddleHit->position.x + Paddle::PADDLE_WIDTH + SIDE_LENGTH;
	}
}

void Ball::reset()
{
	position.x = (float)Game::WINDOW_WIDTH / 2;
	position.y = (float)Game::WINDOW_HEIGHT / 2;

	setInitialSpeed();
}

void Ball::draw(SDL_Renderer* renderer) const
{
	SDL_Rect ballRectangle = { position.x, position.y, SIDE_LENGTH, SIDE_LENGTH };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &ballRectangle);
}
