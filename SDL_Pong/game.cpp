#include "game.h"
#include <SDL.h>
#include <stdio.h>

#include "playerinputcomponent.h"
#include "aiinputcomponent.h"
#include "ball.h"
#include "paddle.h"
#include <iostream>

Game::Game() : renderer(nullptr), window(nullptr), quitGame(false)
{
	Paddle* player = new Paddle(Paddle::PADDLE_OFFSET , WINDOW_HEIGHT / 2, new PlayerInputComponent());
	Paddle* enemy = new Paddle(WINDOW_WIDTH - Paddle::PADDLE_OFFSET, WINDOW_HEIGHT / 2);
	Ball* ball = new Ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, player, enemy);

	AIInputComponent* aiInput = new AIInputComponent(ball);
	enemy->setInputComponent(aiInput);

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
			renderer = SDL_CreateRenderer(window, 01, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
	double previous = SDL_GetTicks64();
	double totalElapsed = 0.0f;
	while (!quitGame)
	{
		double current = SDL_GetTicks64();
		double elapsed = current - previous;
		previous = current;

		handleEventLoop(quitGame, elapsed);
		update(elapsed);
		totalElapsed += elapsed;

		if (totalElapsed > MS_PER_UPDATE)
		{
			draw();
			totalElapsed -= MS_PER_UPDATE;
			if (totalElapsed > MS_PER_UPDATE)
			{
				std::cout << "Performance warning, rendering or update took too long" << std::endl;
			}
		}
	}
}

void Game::handleEventLoop(bool& quitGame, double deltaTime) const
{
	while (SDL_PollEvent(sdlEvent) != 0)
	{
		if (sdlEvent->type == SDL_QUIT)
		{
			quitGame = true;
		}
	}

	getPlayer()->handleInput(deltaTime);
	getEnemy()->handleInput(deltaTime);
}

void Game::update(double deltaTime) const
{
	for (int i = 0; i < NUMBER_OF_GAME_OBJECTS; i++)
	{
		gameObjects[i]->update(deltaTime);
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

Paddle* Game::getPlayer() const
{
	return static_cast<Paddle*>(gameObjects[PLAYER_INDEX]);
}

Paddle* Game::getEnemy() const
{
	return static_cast<Paddle*>(gameObjects[ENEMY_INDEX]);
}
