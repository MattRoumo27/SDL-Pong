#pragma once

#include "gameobject.h"

// Player paddle, enemy paddle, and the ball
const int NUMBER_OF_GAME_OBJECTS = 3;

class Game
{
public:
	Game();
	~Game();

	bool initializeSDLSystems();
	void update() const;
	void draw() const;
	struct SDL_Window* getWindow() const;
	struct SDL_Renderer* getRenderer() const;
	class Player* getPlayer() const;

	const char* GAME_TITLE = "Pong";
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	GameObject* gameObjects[NUMBER_OF_GAME_OBJECTS];

	typedef enum
	{
		PLAYER_INDEX,
		ENEMY_INDEX,
		BALL_INDEX
	} GameObjectIndexes;
};