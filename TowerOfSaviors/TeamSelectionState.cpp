#include "TeamSelectionState.h"

TeamSelectionState::TeamSelectionState(std::stack<State*>* states_stack_ptr)
{
	statesptr = states_stack_ptr;
	std::cout << "YOU ARE IN Team Selection to choose your disired team monsters.\n\n";

	team_selection_bg_t.loadFromFile("images/team_selection.png");
	team_selection_bg.setTexture(team_selection_bg_t);

	battle_button.setSize(sf::Vector2f(100, 40));
	battle_button.setPosition(sf::Vector2f(225 - 50, 600));
	battle_button.setFillColor(sf::Color::Red);

	team_shape.setSize(sf::Vector2f(380, 86));
	team_shape.setPosition(sf::Vector2f(38, 513));
	team_shape.setOutlineColor(sf::Color::Yellow);
	team_shape.setOutlineThickness(0.59);
	team_shape.setFillColor(sf::Color::Transparent);

	delete_button.setSize(sf::Vector2f(100, 40));
	delete_button.setPosition(sf::Vector2f(300, 615));
	delete_button.setFillColor(sf::Color::Transparent);
	delete_button.setOutlineColor(sf::Color::Cyan);
	delete_button.setOutlineThickness(0.59);

	if (!battle_button_txt_font.loadFromFile("fonts/AncientModernTales-a7Po.ttf"))
	{
		std::cout << "Font not loaded\n";
	}

	battle_button_txt.setFont(battle_button_txt_font);
	battle_button_txt.setString("BATTLE");
	battle_button_txt.setCharacterSize(20);
	battle_button_txt.setFillColor(sf::Color());
	battle_button_txt.setStyle(sf::Text::Bold);
	battle_button_txt.setPosition(battle_button.getPosition().x + 25, battle_button.getPosition().y + 25);

	team_selection_txt_font.loadFromFile("fonts/AncientModernTales-a7Po.ttf");
	team_selection_txt.setFont(team_selection_txt_font);
	team_selection_txt.setString("Team Selection");
	team_selection_txt.setCharacterSize(30);
	team_selection_txt.setFillColor(sf::Color::White);
	team_selection_txt.setStyle(sf::Text::Bold);
	team_selection_txt.setPosition(15, 145);

	instruction_txt_font.loadFromFile("fonts/Montserrat-ExtraLight.ttf");
	instruction_txt.setFont(instruction_txt_font);
	instruction_txt.setString("Clicks the monsters to add to your team");
	instruction_txt.setCharacterSize(20);
	instruction_txt.setFillColor(sf::Color::White);
	instruction_txt.setStyle(sf::Text::Regular);
	instruction_txt.setPosition(15, 180);

	your_team_txt_font.loadFromFile("fonts/AncientModernTales-a7Po.ttf");
	your_team_txt.setFont(your_team_txt_font);
	your_team_txt.setString("Your Team");
	your_team_txt.setCharacterSize(35);
	your_team_txt.setFillColor(sf::Color::White);
	your_team_txt.setStyle(sf::Text::Regular);
	your_team_txt.setPosition(15, 470);

	clear_txt_font.loadFromFile("fonts/Montserrat-ExtraLight.ttf");
	clear_txt.setFont(clear_txt_font);
	clear_txt.setString("CLEAR");
	clear_txt.setCharacterSize(20);
	clear_txt.setFillColor(sf::Color::Cyan);
	clear_txt.setStyle(sf::Text::Bold);
	clear_txt.setPosition(315,623);

	monster1_t.loadFromFile("images/1Dragon.jpg");
	monster1_bg.setTexture(monster1_t);
	monster1s_bg.setTexture(monster1_t);
	monster1_bg.setPosition(53, 215);

	monster2_t.loadFromFile("images/2Duncan.jpg");
	monster2_bg.setTexture(monster2_t);
	monster2s_bg.setTexture(monster2_t);
	monster2_bg.setPosition(187, 215);

	monster3_t.loadFromFile("images/3Viscount.jpg");
	monster3_bg.setTexture(monster3_t);
	monster3s_bg.setTexture(monster3_t);
	monster3_bg.setPosition(321, 215);

	monster4_t.loadFromFile("images/4Molly.jpg");
	monster4_bg.setTexture(monster4_t);
	monster4s_bg.setTexture(monster4_t);
	monster4_bg.setPosition(53, 300);

	monster5_t.loadFromFile("images/5Solace.jpg");
	monster5_bg.setTexture(monster5_t);
	monster5s_bg.setTexture(monster5_t);
	monster5_bg.setPosition(187, 300);

	monster6_t.loadFromFile("images/6Urd.jpg");
	monster6_bg.setTexture(monster6_t);
	monster6s_bg.setTexture(monster6_t);
	monster6_bg.setPosition(321, 300);

	monster7_t.loadFromFile("images/7Khee.jpg");
	monster7_bg.setTexture(monster7_t);
	monster7s_bg.setTexture(monster7_t);
	monster7_bg.setPosition(53, 385);

	monster8_t.loadFromFile("images/8Lilith.jpg");
	monster8_bg.setTexture(monster8_t);
	monster8s_bg.setTexture(monster8_t);
	monster8_bg.setPosition(187, 385);

	monster9_t.loadFromFile("images/9Lunar.jpg");
	monster9_bg.setTexture(monster9_t);
	monster9s_bg.setTexture(monster9_t);
	monster9_bg.setPosition(321, 385);

	for (int i = 0; i < 3; i++)
	{ chararcter_selected_array[i] = 0;}
	click = 0;
	is_Clicked = false;
	is_Deleted = false;
	is_Empty = false;
}

TeamSelectionState::~TeamSelectionState()
{
	
}

void TeamSelectionState::updateEvent(sf::Event e)
{
	

	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
	{
		
			if (battle_button.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
			{
				if (click == 3)
				{
					(*statesptr).push(new BattleState(statesptr, chararcter_selected_array, 3));
				}
			}

			if (!is_Clicked)
			{
				if (monster1_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(1) == true)
					{
						chararcter_selected_array[click] = 1;
						std::cout << "Choice " << click+1<<": Flamer. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}

				else if (monster2_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(2) == true)
					{
						chararcter_selected_array[click] = 2;
						std::cout << "Choice " << click + 1 << ": Cleric Duncan. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}

				else if (monster3_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(3) == true)
					{
						chararcter_selected_array[click] = 3;
						std::cout << "Choice " << click + 1 << ": Baron Nathaniel. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}

				else if (monster4_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(4) == true)
					{
						chararcter_selected_array[click] = 4;
						std::cout << "Choice " << click + 1 << ": Molly. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}

				else if (monster5_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(5) == true)
					{
						chararcter_selected_array[click] = 5;
						std::cout << "Choice " << click + 1 << ": Solace Endor. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}

				else if (monster6_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(6) == true)
					{
						chararcter_selected_array[click] = 6;
						std::cout << "Choice " << click + 1 << ": Urd, Goddess of History. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}

				else if (monster7_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(7) == true)
					{
						chararcter_selected_array[click] = 7;
						std::cout << "Choice " << click + 1 << ": Byakhee the Cosmic Berserker. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}

				else if (monster8_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(8) == true)
					{
						chararcter_selected_array[click] = 8;
						std::cout << "Choice " << click + 1 << ": Lilith the Alchemist. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}

				else if (monster9_bg.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
				{
					if (check_selected(8) == true) {
						chararcter_selected_array[click] = 9;
						std::cout << "Choice " << click + 1 << ": Silvery Lunar Elf. " << std::endl;
						click++;
						is_Clicked = true;
						is_Deleted = false;
					}
				}
				
				if (click > 2)
				{
					std::cout << "You have selected 3 monster" << std::endl;
				}
			}

			if (delete_button.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
			{
				for (int i = 0; i < 3; i++)
				{chararcter_selected_array[i] = 0;}
				is_Deleted = true;
				is_Clicked = false;
				click = 0;
			}
	}

	if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left)
	{
		is_Clicked = false;
	}
}

void TeamSelectionState::update()
{
}

void TeamSelectionState::render(sf::RenderWindow& window)
{
	window.draw(team_selection_bg);
	window.draw(team_selection_txt);
	window.draw(instruction_txt);
	window.draw(your_team_txt);
	window.draw(monster1_bg);
	window.draw(monster2_bg);
	window.draw(monster3_bg);
	window.draw(monster4_bg);
	window.draw(monster5_bg);
	window.draw(monster6_bg);
	window.draw(monster7_bg);
	window.draw(monster8_bg);
	window.draw(monster9_bg);
	window.draw(team_shape);
	window.draw(delete_button);
	window.draw(clear_txt);
	window.draw(battle_button);

	if(!is_Deleted)
	{
		for (int i = 0; i < 3; i++)
		{

			if (chararcter_selected_array[i] == 1)
			{
				monster1s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster1s_bg);
			}

			else if (chararcter_selected_array[i] == 2)
			{
				monster2s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster2s_bg);
			}

			else if (chararcter_selected_array[i] == 3)
			{
				monster3s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster3s_bg);
			}

			else if (chararcter_selected_array[i] == 4)
			{
				monster4s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster4s_bg);
			}

			else if (chararcter_selected_array[i] == 5)
			{
				monster5s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster5s_bg);
			}

			else if (chararcter_selected_array[i] == 6)
			{
				monster6s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster6s_bg);
			}

			else if (chararcter_selected_array[i] == 7)
			{
				monster7s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster7s_bg);
			}

			else if (chararcter_selected_array[i] == 8)
			{
				monster8s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster8s_bg);
			}

			else if (chararcter_selected_array[i] == 9)
			{
				monster9s_bg.setPosition(53 + i * 134, 515);
				window.draw(monster9s_bg);
			}
		}
	}
}

void TeamSelectionState::endState()
{
}

bool TeamSelectionState::check_selected(int searchkey)
{
	for (int i = 0; i < 3; i++)
	{
		if (chararcter_selected_array[i] == searchkey)
		{
			return false;
			break;
		}
		if (i == 2)
		{
			return true;
			break;
		}
	}
}

