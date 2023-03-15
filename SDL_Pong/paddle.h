#pragma once
#include "gameobject.h"

class Paddle: public GameObject
{
public:
	Paddle(float _x, float _y);
	virtual void update();

	const float PADDLE_WIDTH = 10;
	const float PADDLE_HEIGHT = 60;
	void draw(struct SDL_Renderer* renderer) const;

private:
	float getBottomYCoordinate() const;
};

