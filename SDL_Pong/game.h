#pragma once

#include "gameobject.h"
#include "scoreboard.h"
#include <SDL.h>

// Player paddle, enemy paddle, and the ball
const int NUMBER_OF_GAME_OBJECTS = 3;

class Game
{
public:
	Game();
	~Game();

	bool initializeSDLSystems();
	void gameLoop();
	void handleEventLoop(bool& quitGame, double deltaTime) const;
	void update(double deltaTime) const;
	void draw() const;
	SDL_Window* getWindow() const;
	SDL_Renderer* getRenderer() const;

	const char* GAME_TITLE = "Pong";
	static const int WINDOW_WIDTH = 640;
	static const int WINDOW_HEIGHT = 480;

private:
	class Paddle* getPlayer() const;
	Paddle* getEnemy() const;

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* sdlEvent;
	Scoreboard* scoreboard;
	GameObject* gameObjects[NUMBER_OF_GAME_OBJECTS];
	bool quitGame;
	const float MS_PER_UPDATE = 10;

	typedef enum
	{
		PLAYER_INDEX,
		ENEMY_INDEX,
		BALL_INDEX
	} GameObjectIndexes;
};