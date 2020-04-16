#pragma once



#include"BattleState.h"
#include"Monster.h"
#include"MainMenuState.h"

class Game
{
private:
	// Variables
	sf::RenderWindow window;
	std::stack<State*> states;
	sf::Event sfEvent;

	// For grid
	int ts = 75;
	sf::Vector2i offset;
	sf::Texture bg_texture, diamonds_texture;
	sf::Sprite background, diamonds;

	//States for button/events
	bool mouseClicked = false;
	bool mouseInsideRect = false;
	bool dragging = false;
	bool dragged = false;

	sf::Vector2f mouseRectOffset;

	//Variables
	int mouseX = 0;
	int mouseY = 0;
	
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

