#pragma once
#include "State.h"
#include "BattleState.h"
#include "TeamSelectionState.h"
class MainMenuState :
	public State
{
	private:
		std::stack<State*>* statesptr;
		sf::Texture main_main_bg_t, start_button_t;
		sf::Sprite main_main_bg, start_button;
		sf::Text start_button_txt;
		sf::Font start_button_txt_font;

	public:
		MainMenuState(std::stack<State*>*);
		virtual ~MainMenuState();

		void updateEvent(sf::Event);
		void update();
		void render(sf::RenderWindow&);
		void endState();
};

