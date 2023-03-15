#include "gameobject.h"

GameObject::GameObject() : x(0), y(0)
{ }

GameObject::GameObject(float _x, float _y): x(_x), y(_y)
{ }

float GameObject::getX() const
{
	return x;
}

float GameObject::getY() const
{
	return y;
}

void GameObject::setX(float _x)
{
	x = _x;
}

void GameObject::setY(float _y)
{
	y = _y;
}

bool GameObject::haveObjectsCollided(GameObject* otherObject)
{
	return false;
}

void GameObject::update()
{ }

void GameObject::draw(SDL_Renderer* renderer) const
{ }