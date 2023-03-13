#pragma once

#include "paddle.h"

class Player: public Paddle
{
public:
	Player(int _x, int _y);
	void update();
};

