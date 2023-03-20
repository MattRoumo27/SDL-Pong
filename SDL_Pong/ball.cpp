#include "ball.h"
#include "paddle.h"
#include "game.h"
#include <SDL.h>
#include <cmath>
#include <cstdlib>
#include "observer.h"

const float Ball::SIDE_LENGTH = 10;

Ball::Ball(float _x, float _y, Paddle* leftPaddle, Paddle* rightPaddle) : GameObject(_x, _y), leftPaddle(leftPaddle), rightPaddle(rightPaddle)
{
	setInitialSpeed();
	for (int i = 0; i < MAX_OBSERVERS; i++)
	{
		observers[i] = nullptr;
	}
}

void Ball::setInitialSpeed()
{
	speedVector.x = RIGHT_DIRECTION * INITIAL_SPEED;
	speedVector.y = (-3 + (rand() % 6)) * (INITIAL_SPEED / 2);

	while (speedVector.y == 0)
	{
		speedVector.y = (-3 + (rand() % 6)) * (INITIAL_SPEED / 2);
	}
}

void Ball::update(double deltaTime)
{
	position.x += speedVector.x * (float)deltaTime;
	position.y += speedVector.y * (float)deltaTime;

	handleOutOfBounds();
	handlePaddleCollisions();
}

void Ball::handleOutOfBounds()
{
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
		if (position.x < 0)
		{
			notifyObservers(GameEvent::RIGHT_PADDLE_SCORED);
		}
		else
		{
			notifyObservers(GameEvent::LEFT_PADDLE_SCORED);
		}
		reset();
	}
}

void Ball::handlePaddleCollisions()
{
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
	float relativeIntersectY = paddleHit->getCenterYCoordinate() - (position.y + SIDE_LENGTH / 2);
	float normalizedRelativeIntersectionY = (relativeIntersectY / (Paddle::PADDLE_HEIGHT / 2)) * (3.1479 / 2 - MAX_BOUNCE_ANGLE);
	float bounceAngle = normalizedRelativeIntersectionY * MAX_BOUNCE_ANGLE;

	if (speedVector.x > 0)
	{
		speedVector.x = SPEED_MULTIPLIER * speedVector.getLength() * cos(bounceAngle) * -1;
		speedVector.y = SPEED_MULTIPLIER * speedVector.getLength() * sin(bounceAngle) * -1;
		position.x = paddleHit->position.x - SIDE_LENGTH;
	}
	else
	{
		speedVector.x = SPEED_MULTIPLIER * speedVector.getLength() * cos(bounceAngle);
		speedVector.y = SPEED_MULTIPLIER * speedVector.getLength() * -sin(bounceAngle);
		position.x = paddleHit->getRightXCoordinate() + SIDE_LENGTH;
	}
}


void Ball::notifyObservers(GameEvent gameEvent)
{
	for (int i = 0; i < MAX_OBSERVERS; i++)
	{
		if (observers[i] != nullptr)
		{
			observers[i]->onNotify(gameEvent);
		}
	}
}

void Ball::addObserver(Observer* observer)
{
	for (int i = 0; i < MAX_OBSERVERS; i++)
	{
		if (observers[i] == nullptr)
		{
			observers[i] = observer;
			break;
		}
	}
}

void Ball::reset()
{
	resetPosition();
	leftPaddle->resetPosition();
	rightPaddle->resetPosition();

	setInitialSpeed();
}

void Ball::draw(SDL_Renderer* renderer) const
{
	SDL_Rect ballRectangle = { position.x, position.y, SIDE_LENGTH, SIDE_LENGTH };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &ballRectangle);
}
