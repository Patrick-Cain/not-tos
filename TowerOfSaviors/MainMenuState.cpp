#include "MainMenuState.h"

MainMenuState::MainMenuState(std::stack<State*>* states_stack_ptr)
{
	statesptr = states_stack_ptr;
	std::cout << "YOU ARE IN MAIN MENU\n";
	std::cout << "NO music yet\n";
	start_button.setSize(sf::Vector2f(100, 40));
	start_button.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::update(sf::Event e)
{	
	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
	{
		if (start_button.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
		{
			(*statesptr).push(new BattleState());
		}
	}	
}

void MainMenuState::render(sf::RenderWindow& window)
{
	window.draw(start_button);
}

void MainMenuState::endState()
{
}
