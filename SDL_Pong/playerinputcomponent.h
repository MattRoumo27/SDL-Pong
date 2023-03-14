#pragma once
class PlayerInputComponent
{
public:
	PlayerInputComponent();
	void handleInput(class Player* player, union SDL_Event* sdlEvent);
};

