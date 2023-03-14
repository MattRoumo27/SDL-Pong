#pragma once

#include "gameobject.h"
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
	void handleEventLoop(bool& quitGame) const;
	void update() const;
	void draw() const;
	SDL_Window* getWindow() const;
	SDL_Renderer* getRenderer() const;
	class Player* getPlayer() const;

	const char* GAME_TITLE = "Pong";
	static const int WINDOW_WIDTH = 640;
	static const int WINDOW_HEIGHT = 480;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* sdlEvent;
	GameObject* gameObjects[NUMBER_OF_GAME_OBJECTS];
	bool quitGame;

	typedef enum
	{
		PLAYER_INDEX,
		ENEMY_INDEX,
		BALL_INDEX
	} GameObjectIndexes;
};