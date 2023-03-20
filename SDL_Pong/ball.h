#pragma once

#include "gameobject.h"
#include "pvector.h"
#include "gameevent.h"

// Increase this to add more observers
const int MAX_OBSERVERS = 1;

class Ball: public GameObject
{
public:
	Ball(float _x, float _y, class Paddle* leftPaddle, Paddle* rightPaddle);
	void update(double deltaTime);

	static const float SIDE_LENGTH;
	void draw(struct SDL_Renderer* renderer) const;

	void addObserver(class Observer* observer);

protected:
	void notifyObservers(GameEvent gameEvent);

private:
	void handleOutOfBounds();
	void handlePaddleCollisions();
	bool hasHitPaddle(Paddle* paddle);
	void handlePaddleHit(Paddle* paddleHit);
	void reset();
	void setInitialSpeed();

	PVector speedVector;
	Paddle* leftPaddle;
	Paddle* rightPaddle;
	Observer* observers[MAX_OBSERVERS];

	typedef enum
	{
		LEFT_DIRECTION = -1,
		UP_DIRECTION = -1,
		RIGHT_DIRECTION = 1,
		DOWN_DIRECTION = 1
	} BallDirection;

	const float INITIAL_SPEED = 0.3;
	const float MAXIMUM_SPEED = 2;
	const float SPEED_MULTIPLIER = 1.1;
	const float MAX_BOUNCE_ANGLE = 1.309;
};

