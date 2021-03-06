#include "BattleState.h"

BattleState::BattleState(std::stack<State*>* states_stack_ptr, int team_id[], int size, int* monster_hp, int* monster_attack, int* kind_arr)
	: battle(&(grid1.clicked), &(grid1.spinning), &(grid1.time_up), team_id, 3, monster_hp, monster_attack, kind_arr)
{
	statesptr = states_stack_ptr;
}

BattleState::~BattleState()
{
}

void BattleState::updateEvent(sf::Event e)
{
	if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
	{
		mouse_clicked.x = e.mouseButton.x;
		mouse_clicked.y = e.mouseButton.y;
		grid1.clicked = true;
		grid1.released = false;
	}

	if (e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left)
	{
		grid1.spinning = false;
		grid1.released = true;
	}

	if (e.type == sf::Event::MouseMoved)
	{
		mouse_dragging.x = e.mouseMove.x;
		mouse_dragging.y = e.mouseMove.y;
	}
	
}

void BattleState::update()
{
	grid1.updateGrid(mouse_clicked, mouse_dragging);
	battle.updateTeamHP(&grid1.launchattack, grid1.numberofstonedeleted, 6);
	if (battle.getCurrentTeamHP() <= 0) {
		std::cout << "YOU DIED\n";
		this->setQuit();
	}
	if (battle.getEnemyDied()) {
		std::cout << "ENEMY DIED, YOU WIN\n";
		this->setQuit();
	}
	battle.updateTime(&grid1.time_up);
}

void BattleState::render(sf::RenderWindow& window)
{
	battle.drawall(window);
	grid1.draw(window);
}

void BattleState::endState()
{
}
