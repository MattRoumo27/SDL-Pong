#include "gameobject.h"
#include "pvector.h"

GameObject::GameObject()
{ 
	position = PVector();
	initialPosition = position;
}

GameObject::GameObject(float _x, float _y)
{ 
	position = PVector(_x, _y);
	initialPosition = position;
}

void GameObject::update(double deltaTime)
{ }

void GameObject::draw(SDL_Renderer* renderer) const
{ }

void GameObject::resetPosition()
{
	position = initialPosition;
}
