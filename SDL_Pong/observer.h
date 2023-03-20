#pragma once

#include "gameevent.h"

class Observer
{
public:
	virtual ~Observer();
	virtual void onNotify(GameEvent gameEvent) = 0;
};

