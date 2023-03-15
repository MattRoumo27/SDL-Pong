#pragma once

#include "gameobject.h"

class Ball: public GameObject
{
public:
	Ball(float _x, float _y, class Paddle* leftPaddle, Paddle* rightPaddle);
	void update();

	static const float SIDE_LENGTH;
	void draw(struct SDL_Renderer* renderer) const;

private:
	bool hasHitPaddle(Paddle* paddle);
	void handlePaddleHit(Paddle* paddleHit);
	void reset();

	float xSpeed;
	float ySpeed;
	Paddle* leftPaddle;
	Paddle* rightPaddle;

	typedef enum
	{
		LEFT_DIRECTION = -1,
		UP_DIRECTION = -1,
		RIGHT_DIRECTION = 1,
		DOWN_DIRECTION = 1
	} BallDirection;

	const float INITIAL_BALL_SPEED = 2;
	const float SPEED_MULTIPLIER = 1.1;
	const float MAX_BOUNCE_ANGLE = 1.309;
};

