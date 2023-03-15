#include "aiinputcomponent.h"
#include "paddle.h"
#include "ball.h"
#include <SDL.h>

AIInputComponent::AIInputComponent(Ball* ball) : ball(ball)
{ }

void AIInputComponent::handleInput(Paddle* paddle, double deltaTime)
{
	float paddleCenter = paddle->position.y + Paddle::PADDLE_HEIGHT / 2.f;
	float ballCenter = ball->position.y + Ball::SIDE_LENGTH / 2.f;

	if (paddleCenter > ballCenter)
	{
		paddle->position.y -= Paddle::MOVE_SPEED * 0.75f * (float)deltaTime;
	}
	else if (paddleCenter < ballCenter)
	{
		paddle->position.y += Paddle::MOVE_SPEED * 0.75f * (float)deltaTime;
	}
}
