#pragma once
#include "inputcomponent.h"

class AIInputComponent : public InputComponent
{
public:
	AIInputComponent(class Ball* ball);
	virtual void handleInput(class Paddle* paddle, union SDL_Event* sdlEvent);

private:
	Ball* ball;
};

