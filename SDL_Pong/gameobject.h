#pragma once
#include "pvector.h"

class GameObject
{
public:
	GameObject();
	GameObject(float _x, float _y);

	virtual void update(double deltaTime);
	virtual void draw(struct SDL_Renderer* renderer) const;

	PVector position;
};

