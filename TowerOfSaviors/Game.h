#pragma once

#include"BattleState.h"
#include"MainMenuState.h"

class Game
{
private:
	// Variables
	sf::RenderWindow window;
	std::stack<State*> states;
	sf::Event sfEvent;
	
	
	
	// Initialization
	void initWindows();

public:
	// Constructors/Destructors
	Game();
	virtual ~Game();

	// Functions
	void updateSFMLEvents();
	void update();
	void render();
	void run();

};

