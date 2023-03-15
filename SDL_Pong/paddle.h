#pragma once
#include "gameobject.h"

class Paddle: public GameObject
{
public:
	Paddle(float _x, float _y);
	Paddle(float _x, float _y, class InputComponent* inputComponent);
	~Paddle();

	void update(double deltaTime);
	void setInputComponent(InputComponent* _inputComponent);
	void handleInput(double deltaTime);
	void draw(struct SDL_Renderer* renderer) const;

	static const float PADDLE_WIDTH;
	static const float PADDLE_HEIGHT;
	static const float PADDLE_OFFSET;
	static const float MOVE_SPEED;

private:
	float getBottomYCoordinate() const;
	InputComponent* inputComponent;
};

