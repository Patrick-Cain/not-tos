#pragma once
#include "State.h"
#include "BattleState.h"
class MainMenuState :
	public State
{
	private:
		std::stack<State*>* statesptr;
		sf::RectangleShape start_button;
		bool startbattle=false;

	public:
		MainMenuState(std::stack<State*>*);
		virtual ~MainMenuState();

		void update(sf::Event);
		void render(sf::RenderWindow&);
		void endState();
};

