#pragma once
#include "inputcomponent.h"

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	virtual void handleInput(class Paddle* player, union SDL_Event* sdlEvent);
};

