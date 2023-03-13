#pragma once
#include "gameobject.h"

class Paddle: public GameObject
{
public:
	Paddle(int _x, int _y);
	virtual void update();

	const int PADDLE_WIDTH = 10;
	const int PADDLE_HEIGHT = 60;
	void draw(struct SDL_Renderer* renderer) const;
};

