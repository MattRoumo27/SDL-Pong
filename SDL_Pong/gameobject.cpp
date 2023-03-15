#include "gameobject.h"
#include "pvector.h"

GameObject::GameObject()
{ 
	position = PVector();
}

GameObject::GameObject(float _x, float _y)
{ 
	position = PVector(_x, _y);
}

void GameObject::update(double deltaTime)
{ }

void GameObject::draw(SDL_Renderer* renderer) const
{ }