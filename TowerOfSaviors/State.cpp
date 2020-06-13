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

void State::setQuit()
{
	this->quit = true;
}
