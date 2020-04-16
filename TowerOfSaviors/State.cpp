#include "State.h"

State::State()
{
}

State::~State()
{
}

bool State::getQuit()
{
	return quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}
