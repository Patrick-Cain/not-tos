#include "BattleState.h"

BattleState::BattleState() : battle(0)
{
	std::cout << "BATTLE!!";
	battle.playmusic();
}

BattleState::~BattleState()
{
}

void BattleState::update(sf::Event e)
{
	battle.setCurrentTeamHP(--number);
}

void BattleState::render(sf::RenderWindow& window)
{
	battle.drawall(window);
}

void BattleState::endState()
{
}
