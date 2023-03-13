#pragma once

#include "gameobject.h"

class Ball: public GameObject
{
public:
	Ball(int _x, int _y);
	void update();

	const int SIDE_LENGTH = 10;
	void draw(struct SDL_Renderer* renderer) const;

private:
	int xSpeed;
	int ySpeed;

	typedef enum
	{
		LEFT_DIRECTION = -1,
		UP_DIRECTION = -1,
		RIGHT_DIRECTION = 1,
		DOWN_DIRECTION = 1
	} BallDirection;

	const int INITIAL_BALL_SPEED = 1;
};

