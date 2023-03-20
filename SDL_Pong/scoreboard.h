#pragma once

#include "observer.h"
#include "gameevent.h"

class Scoreboard : public Observer
{
public:
	Scoreboard();
	virtual ~Scoreboard();
	virtual void onNotify(GameEvent gameEvent);

private:
	void printScore();

	int leftScore;
	int rightScore;
};

