#pragma once

#include "gameobject.h"
#include "pvector.h"

class Ball: public GameObject
{
public:
	Ball(float _x, float _y, class Paddle* leftPaddle, Paddle* rightPaddle);
	void update(double deltaTime);

	static const float SIDE_LENGTH;
	void draw(struct SDL_Renderer* renderer) const;

private:
	bool hasHitPaddle(Paddle* paddle);
	void handlePaddleHit(Paddle* paddleHit);
	void reset();
	void setInitialSpeed();

	PVector speedVector;
	Paddle* leftPaddle;
	Paddle* rightPaddle;

	typedef enum
	{
		LEFT_DIRECTION = -1,
		UP_DIRECTION = -1,
		RIGHT_DIRECTION = 1,
		DOWN_DIRECTION = 1
	} BallDirection;

	const float INITIAL_SPEED = 2000;
	const float MAXIMUM_SPEED = 15000;
	const float SPEED_MULTIPLIER = 1.1;
	const float MAX_BOUNCE_ANGLE = 1.309;
};

