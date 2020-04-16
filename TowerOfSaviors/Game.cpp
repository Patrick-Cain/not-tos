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
	// loading texture
	bg_texture.loadFromFile("images/background.png");
	diamonds_texture.loadFromFile("images/diamonds.png");
	
	// set up diamonds sprite and background sprite
	background.setTexture(bg_texture);
	diamonds.setTexture(diamonds_texture);

	// Set initial position of all diamonds
	diamonds.setPosition(0, 450);

}

Game::~Game()
{
	// Destroyed all the states created as it is heap memory
	while (!states.empty()) {
		delete states.top();
		states.pop();
	}
}

void Game::updateSFMLEvents()
{
	while (window.pollEvent(sfEvent)) {
		if (sfEvent.type == sf::Event::Closed)
			window.close();
		if (sfEvent.type == sf::Event::MouseButtonPressed && sfEvent.mouseButton.button == sf::Mouse::Left)
		{
			if (diamonds.getGlobalBounds().contains(sfEvent.mouseButton.x, sfEvent.mouseButton.y))
			{
				dragging = true;
				mouseRectOffset.x = sfEvent.mouseButton.x - diamonds.getGlobalBounds().left;
				mouseRectOffset.y = sfEvent.mouseButton.y - diamonds.getGlobalBounds().top;
			}
		}
		if (sfEvent.type == sf::Event::MouseButtonReleased && sfEvent.mouseButton.button == sf::Mouse::Left)
		{
			dragging = false;
			dragged = true;

		}

		//Mouse Moved in window
		if (sfEvent.type == sf::Event::MouseMoved)
		{
			mouseX = sfEvent.mouseMove.x;
			mouseY = sfEvent.mouseMove.y;

			// Debugging code
			//std::cout << "Mouse X: " << mouseX;
			//std::cout << " Mouse Y: " << mouseY << std::endl;
		}
	}
}

void Game::update()
{
	this->updateSFMLEvents();
	if (!states.empty()) {
		states.top()->update(sfEvent);

		if (states.top()->getQuit()) {
			states.top()->endState();
			delete states.top();
			states.pop();
		}
	}
	else { // Application ends
		window.close();
	}

	/*if (dragged_updated)
	{
		 battle.getTotalTeamAttack();
		 while(attack>0)
		 find lowest hp enemy
		 give attack to lowest hp of enenmy **
		 if enemyhp==0, delete

		 calculate enemy attack
		 give attack to total team hp

	}*/
}

void Game::render()
{
	window.clear();
	if (!states.empty())
	{
		states.top()->render(window);
	}
	
	// Rendering runestone bg
	background.setPosition(0, 380);
	window.draw(background);
	
	// Rendering the runestone
	diamonds.setTextureRect(sf::IntRect(0 * 75, 0, 75, 75));
	diamonds.setColor(sf::Color(255, 255, 255, 255));
	if (dragging == true)
	{
		// set the position to the dragged position
		// need to minus offset cuz the position of diamonds cannot be set directly to the mouse position
		diamonds.setPosition(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
	}
	else if (dragged) {
		// check which tile it get drop on
		int newx = (diamonds.getPosition().x + 64) / ts;
		int newy = (diamonds.getPosition().y + 64) / ts;
		// times tilesezie to get the dopped x and y
		diamonds.setPosition(newx * ts, newy * ts);

		// tell the program we updated the dropped position
		dragged = false;

		// Debugging code
		// std::cout << "X: "<<diamonds.getPosition().x << std::endl;
		// std::cout << "Y: " << diamonds.getPosition().y << std::endl;
	}
	window.draw(diamonds);

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
