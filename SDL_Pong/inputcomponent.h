#pragma once
class InputComponent
{
public:
	InputComponent();
	virtual void handleInput(class Paddle* paddle, union SDL_Event* sdlEvent) = 0;
};

