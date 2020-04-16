#pragma once
#include "State.h"
#include "Battle.h"


class BattleState :
	public State
{
	private:
		Battle battle;
		int number = 9999;

	public:
		BattleState();
		virtual ~BattleState();

		// inherited getQuit()
		// void checkForQuit();

		void update(sf::Event);
		void render(sf::RenderWindow&);
		void endState();
};

