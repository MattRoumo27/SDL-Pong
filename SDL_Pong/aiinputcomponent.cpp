#include "aiinputcomponent.h"
#include "paddle.h"
#include "ball.h"
#include <SDL.h>

AIInputComponent::AIInputComponent(Ball* ball) : ball(ball)
{ }

void AIInputComponent::handleInput(Paddle * paddle, SDL_Event* sdlEvent)
{

}
