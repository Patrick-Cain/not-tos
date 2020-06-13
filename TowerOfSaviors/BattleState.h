#pragma once
#include "State.h"
#include "Battle.h"
#include"Grid.h"


class BattleState :
	public State
{
	private:
		std::stack<State*>* statesptr;
		Battle battle;
		Grid grid1;
		sf::Vector2i mouse_clicked, mouse_dragging;

	public:
		BattleState(std::stack<State*>*, int arr[], int, int*, int*, int*);
		virtual ~BattleState();

		void updateEvent(sf::Event);
		void update();
		void render(sf::RenderWindow&);
		void endState();
};

