#pragma once
class InputComponent
{
public:
	InputComponent();
	virtual void handleInput(class Paddle* paddle, double deltaTime) = 0;
};

