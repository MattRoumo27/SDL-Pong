#pragma once

#include "paddle.h"

class Player: public Paddle
{
public:
	Player(float _x, float _y, class PlayerInputComponent* inputComponent);
	~Player();
	void handleInput(union SDL_Event* sdlEvent);
	void update();

	static const int MOVE_SPEED = 15;

private:
	PlayerInputComponent* inputComponent;
};

