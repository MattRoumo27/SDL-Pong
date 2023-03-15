#pragma once
#include "inputcomponent.h"

class AIInputComponent : public InputComponent
{
public:
	AIInputComponent(class Ball* ball);
	virtual void handleInput(class Paddle* paddle, double deltaTime);

private:
	Ball* ball;
};

