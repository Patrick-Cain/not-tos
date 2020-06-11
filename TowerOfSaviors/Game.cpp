#include "Game.h"

// Static functions


// Initializer functions
void Game::initWindows()
{
	window.create(sf::VideoMode(450, 800), "Tower Of Savior");
}

// Constructors/Destructors
Game::Game()
{
	initWindows();
	states.push(new MainMenuState(&states));

}

Game::~Game()
{
	// Destroyed all the states created as it is heap memory
	while (!states.empty()) {
		delete states.top();
		states.pop();
	}
}



void Game::update()
{
	if (!states.empty()) {
		while (window.pollEvent(sfEvent)) {
			if (sfEvent.type == sf::Event::Closed)
				window.close();
			states.top()->updateEvent(sfEvent);	
		}
		
		states.top()->update();
		if (states.top()->getQuit()) {
			states.top()->endState();
			delete states.top();
			states.pop();
		}
	}
	else { // Application ends
		window.close();
	}
}

void Game::render()
{
	window.clear();
	if (!states.empty())
	{
		states.top()->render(window);
	}
	window.display();
}

void Game::run()
{
	while (window.isOpen())
	{
		this->update();
		this->render();
	}
}
