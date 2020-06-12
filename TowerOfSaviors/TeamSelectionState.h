#pragma once
#include<iostream>
#include"State.h"
#include"BattleState.h"

class TeamSelectionState :
	public State
{
private:
	std::stack<State*>* statesptr;
	sf::RectangleShape team_shape;

	sf::Texture team_selection_bg_t, battle_button_t, delete_button_t;
	sf::Sprite team_selection_bg, battle_button, delete_button;

	sf::Texture monster_catalog_texture[9];
	sf::Sprite monster_catalog[9];
	sf::Sprite monster_selected[9];

	std::string monster_name[9];
	
	sf::Text battle_button_txt, team_selection_txt, instruction_txt, your_team_txt, clear_txt;
	sf::Font battle_button_txt_font, team_selection_txt_font, instruction_txt_font, your_team_txt_font, clear_txt_font;

	int chararcter_selected_array[3];
	int click;
	bool is_Clicked;
	bool is_Deleted;
	bool is_Empty;
	

public:
	TeamSelectionState(std::stack<State*>*);
	virtual ~TeamSelectionState();

	void updateEvent(sf::Event);
	void update();
	void render(sf::RenderWindow&);
	void endState();
	bool check_selected(int);
	
};

