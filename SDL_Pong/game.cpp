#include "game.h"
#include <SDL.h>
#include <stdio.h>

#include "player.h"
#include "playerinputcomponent.h"
#include "ball.h"
#include "paddle.h"

Game::Game() : renderer(nullptr), window(nullptr), quitGame(false)
{
	Player* player = new Player(50, WINDOW_HEIGHT / 2, new PlayerInputComponent());
	Paddle* enemy = new Paddle(WINDOW_WIDTH - 50, WINDOW_HEIGHT / 2);
	Ball* ball = new Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	gameObjects[PLAYER_INDEX] = player;
	gameObjects[ENEMY_INDEX] = enemy;
	gameObjects[BALL_INDEX] = ball;

	sdlEvent = new SDL_Event;
}

Game::~Game()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;

	SDL_Quit();

	for (int i = 0; i < NUMBER_OF_GAME_OBJECTS; i++)
	{
		delete gameObjects[i];
		gameObjects[i] = nullptr;
	}

	delete sdlEvent;
}

bool Game::initializeSDLSystems()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, 01, SDL_RENDERER_ACCELERATED);
			if (renderer == nullptr)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
			}
		}
	}

	return success;
}

void Game::gameLoop()
{
	while (!quitGame)
	{
		handleEventLoop(quitGame);
		update();
		draw();
	}
}

void Game::handleEventLoop(bool& quitGame) const
{
	while (SDL_PollEvent(sdlEvent) != 0)
	{
		if (sdlEvent->type == SDL_QUIT)
		{
			quitGame = true;
		}

		getPlayer()->handleInput(sdlEvent);
	}
}

void Game::update() const
{
	for (int i = 0; i < NUMBER_OF_GAME_OBJECTS; i++)
	{
		gameObjects[i]->update();
	}
}

void Game::draw() const
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);

	for (int i = 0; i < NUMBER_OF_GAME_OBJECTS; i++)
	{
		gameObjects[i]->draw(renderer);
	}

	SDL_RenderPresent(renderer);
}

SDL_Window* Game::getWindow() const
{
	return window;
}

SDL_Renderer* Game::getRenderer() const
{
	return renderer;
}

Player* Game::getPlayer() const
{
	return static_cast<Player*>(gameObjects[PLAYER_INDEX]);
}
