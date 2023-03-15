#pragma once
#include "gameobject.h"

class Paddle: public GameObject
{
public:
	Paddle(float _x, float _y);
	virtual void update();

	static const float PADDLE_WIDTH;
	static const float PADDLE_HEIGHT;
	void draw(struct SDL_Renderer* renderer) const;

private:
	float getBottomYCoordinate() const;
};

