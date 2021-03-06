#include "MainMenuState.h"

MainMenuState::MainMenuState(std::stack<State*>* states_stack_ptr)
{
	statesptr = states_stack_ptr;
	std::cout << "Welcome To Tower of Saviors\n";

	main_main_bg_t.loadFromFile("images/main_menu.jpg");
	main_main_bg.setTexture(main_main_bg_t);

	start_button_t.loadFromFile("images/start_button1.png");
	start_button.setTexture(start_button_t);
	start_button.setPosition(sf::Vector2f(240, 640));


	if (!start_button_txt_font.loadFromFile("fonts/AncientModernTales-a7Po.ttf"))
	{
		std::cout << "Font not loaded\n";
	}
	start_button_txt.setFont(start_button_txt_font);
	start_button_txt.setString("START");
	start_button_txt.setCharacterSize(20);
	start_button_txt.setFillColor(sf::Color::White);
	start_button_txt.setStyle(sf::Text::Bold);

	start_button_txt.setPosition(start_button.getPosition().x + 53, start_button.getPosition().y + 12);
}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::updateEvent(sf::Event e)
{	
	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
	{
		if (start_button.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
		{
			(*statesptr).push(new TeamSelectionState(statesptr));
		}
	}	
}

void MainMenuState::update()
{
}

void MainMenuState::render(sf::RenderWindow& window)
{
	window.draw(main_main_bg);
	window.draw(start_button);
	window.draw(start_button_txt);
}

void MainMenuState::endState()
{
}
