#include "gameobject.h"

GameObject::GameObject() : x(0), y(0)
{ }

GameObject::GameObject(int _x, int _y): x(_x), y(_y)
{ }

int GameObject::getX() const
{
	return x;
}

int GameObject::getY() const
{
	return y;
}

void GameObject::setX(int _x)
{
	x = _x;
}

void GameObject::setY(int _y)
{
	y = _y;
}

void GameObject::update()
{ }

void GameObject::draw(SDL_Renderer* renderer) const
{ }