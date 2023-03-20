#include "scoreboard.h"
#include <iostream>

Scoreboard::Scoreboard() : leftScore(0), rightScore(0)
{ }

Scoreboard::~Scoreboard()
{ }

void Scoreboard::onNotify(GameEvent gameEvent)
{
	switch (gameEvent)
	{
		case GameEvent::LEFT_PADDLE_SCORED:
			leftScore++;
			break;
		case GameEvent::RIGHT_PADDLE_SCORED:
			rightScore++;
			break;
	}

	printScore();
}

void Scoreboard::printScore()
{
	std::cout << "Left: " << leftScore << " vs. " << "Right: " << rightScore << std::endl;
}
