#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

#include"Monster.h"
#include"Battle.h"

class Game
{
private:
	// Variables
	sf::RenderWindow window;
	sf::Event sfEvent;
	int number = 8888;

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

	// Battle
	Battle battle;
	bool dragged_updated = true;

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

