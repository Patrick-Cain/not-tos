#include "TeamSelectionState.h"

TeamSelectionState::TeamSelectionState(std::stack<State*>* states_stack_ptr) : monster_name{"Flamer", "Cleric Duncan", "Baron Nathaniel", "Molly", "Solace Endor", "Urd, Goddess of History", "Byakhee the Cosmic Berserker", "Lilith the Alchemist", "Silvery Lunar Elf"}
{
	statesptr = states_stack_ptr;
	
	std::cout << "YOU ARE IN Team Selection to choose your disired team monsters.\n\n";

	team_selection_bg_t.loadFromFile("images/team_selection.jpg");
	team_selection_bg.setTexture(team_selection_bg_t);
	
	battle_button_t.loadFromFile("images/play_button.png");
	battle_button.setTexture(battle_button_t);
	battle_button.setPosition(sf::Vector2f(175, 620));

	team_shape.setSize(sf::Vector2f(380, 86));
	team_shape.setPosition(sf::Vector2f(38, 513));
	team_shape.setOutlineColor(sf::Color::Yellow);
	team_shape.setOutlineThickness(0.59);
	team_shape.setFillColor(sf::Color::Transparent);

	delete_button_t.loadFromFile("images/clear_button.png");
	delete_button.setTexture(delete_button_t);
	delete_button.setPosition(sf::Vector2f(300, 625));

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
	team_selection_txt.setPosition(15, 75);

	instruction_txt_font.loadFromFile("fonts/Montserrat-ExtraLight.ttf");
	instruction_txt.setFont(instruction_txt_font);
	instruction_txt.setString("Clicks the monsters to add to your team");
	instruction_txt.setCharacterSize(20);
	instruction_txt.setFillColor(sf::Color::White);
	instruction_txt.setStyle(sf::Text::Regular);
	instruction_txt.setPosition(15, 110);

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
	clear_txt.setCharacterSize(15);
	clear_txt.setFillColor(sf::Color::Cyan);
	clear_txt.setStyle(sf::Text::Bold);
	clear_txt.setPosition(319,630);
	int j = -1;
	for (int i = 0; i < 9; i++)
	{
		std::string file_path_to_image = "images/team" + std::to_string(i+1) + ".png";
		monster_catalog_texture[i].loadFromFile(file_path_to_image);
		monster_catalog[i].setTexture(monster_catalog_texture[i]);
		monster_selected[i].setTexture(monster_catalog_texture[i]);
		int x = 53 + ((i % 3) * 134);
		if (i % 3 == 0)
			j++;
		int y = 215 + j * 85;
		monster_catalog[i].setPosition(x, y);
	}

	for (int i = 0; i < 3; i++){
		chararcter_selected_array[i] = 0;
	}
	click = 0;
	is_Clicked = false;
	is_Deleted = false;
	is_Empty = false;
	for (int i = 0; i < 9; i++)
	{
		std::cout << "Monster " << i + 1 << ": " << monster_name[i] << "\n";
		std::cout << "HP: " << monster_hp[i] << "\t Attack: " << monster_attack[i] << "\n";
	}
	std::cout << "\n";
}

TeamSelectionState::~TeamSelectionState()
{
	
}

void TeamSelectionState::updateEvent(sf::Event e)
{
	// if mouse is clicked
	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
	{
		
			if (battle_button.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
			{
				if (click == 3)
				{
					(*statesptr).push(new BattleState(statesptr, chararcter_selected_array, 3, monster_hp, monster_attack, kind));
				}

				if (click != 3)
				{
					std::cout << "You must select 3 monster into your team before proceeding to the battle.\n";
				}
			}

			else if (!is_Clicked)
			{
				if (click > 2)
				{
					std::cout << "You have selected 3 monster" << std::endl;
				}
				else {
					for (int i = 0; i < 9; i++)
					{
						if (monster_catalog[i].getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)) {
							if (check_selected(i + 1) == true) {
								if (click >= 0 && click <= 2) {
									chararcter_selected_array[click] = i + 1;
								}
								std::cout << "Choice " << click + 1 << ": " << monster_name[i] << ". \n";
								click++;
								is_Clicked = true;
								is_Deleted = false;
							}
						}
					}
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
	for (int i = 0; i < 9; i++)
	{
		window.draw(monster_catalog[i]);
	}
	
	window.draw(team_shape);
	window.draw(delete_button);
	window.draw(clear_txt);
	window.draw(battle_button);

	if(!is_Deleted)
	{
		for (int i = 0; i < 3; i++)
		{
			if (chararcter_selected_array[i] != 0) {
				monster_selected[chararcter_selected_array[i] - 1].setPosition(53 + i * 134, 515);
				window.draw(monster_selected[chararcter_selected_array[i] - 1]);
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
		}
	}
	return true;
}