#pragma once
#include "gameobject.h"

class Paddle: public GameObject
{
public:
	Paddle(float _x, float _y);
	Paddle(float _x, float _y, class InputComponent* inputComponent);
	~Paddle();

	void update();
	void setInputComponent(InputComponent* _inputComponent);
	void handleInput(union SDL_Event* sdlEvent);
	void draw(struct SDL_Renderer* renderer) const;

	static const float PADDLE_WIDTH;
	static const float PADDLE_HEIGHT;
	static const float PADDLE_OFFSET;
	static const int MOVE_SPEED = 15;

private:
	float getBottomYCoordinate() const;
	InputComponent* inputComponent;
};

