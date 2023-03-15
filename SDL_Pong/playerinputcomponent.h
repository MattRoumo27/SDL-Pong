#pragma once
#include "inputcomponent.h"

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	virtual void handleInput(class Paddle* player, double deltaTime);
};

