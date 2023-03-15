#include "aiinputcomponent.h"
#include "paddle.h"
#include "ball.h"
#include <SDL.h>

AIInputComponent::AIInputComponent(Ball* ball) : ball(ball)
{ }

void AIInputComponent::handleInput(Paddle* paddle, double deltaTime)
{
	float paddleCenter = paddle->getY() + Paddle::PADDLE_HEIGHT / 2;
	float ballCenter = ball->getY() + Ball::SIDE_LENGTH / 2;

	if (paddleCenter > ballCenter)
	{
		paddle->setY(paddle->getY() - (Paddle::MOVE_SPEED  * 0.75) * (float)deltaTime);
	}
	else if (paddleCenter < ballCenter)
	{
		paddle->setY(paddle->getY() + (Paddle::MOVE_SPEED * 0.75) * (float)deltaTime);
	}
}
