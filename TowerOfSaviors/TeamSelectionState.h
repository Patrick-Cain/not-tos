#pragma once
#include<iostream>
#include"State.h"
#include"BattleState.h"

class TeamSelectionState :
	public State
{
private:
	std::stack<State*>* statesptr;
	sf::RectangleShape battle_button, team_shape;
	sf::RectangleShape delete_button;

	sf::Texture team_selection_bg_t;
	sf::Sprite team_selection_bg;
	sf::Texture monster1_t, monster2_t, monster3_t, monster4_t, monster5_t, monster6_t, monster7_t, monster8_t, monster9_t;
	sf::Sprite monster1_bg, monster2_bg, monster3_bg, monster4_bg, monster5_bg, monster6_bg, monster7_bg, monster8_bg, monster9_bg;
	sf::Sprite monster1s_bg, monster2s_bg, monster3s_bg, monster4s_bg, monster5s_bg, monster6s_bg, monster7s_bg, monster8s_bg, monster9s_bg;
	
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

