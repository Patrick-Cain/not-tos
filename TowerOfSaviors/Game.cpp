#include "Game.h"

// Static functions


// Initializer functions
void Game::initWindows()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Tower Of Savior");
}

// Constructors/Destructors
Game::Game()
{
	this->initWindows();
}

Game::~Game()
{
	delete this->window;
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateSFMLEvents();
}

void Game::render()
{
	this->window->clear();

	// Render items


	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}
