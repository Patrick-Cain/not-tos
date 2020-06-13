#pragma once
#include"SFML/Graphics.hpp"
#include <iostream>

#include <ctime>
#include <cstdlib>

class Grid
{
private:
	struct piece
	{
		int x =0, y=0, col=0, row=0, kind=0, match=0, alpha=255;
	} grid[10][10];

	sf::Texture bg_texture;
	sf::Sprite background,runestone_sprite;
	sf::Texture runestones_texture;
	sf::Vector2i grid_offset, mouseRectOffset;
	int ts = 75;
	int x0, y0;
	int x, y;
	

public:
	bool spinning = false;
	bool clicked = false, released = false;
	bool time_up = false;
	bool launchattack = false;

	int numberofstonedeleted[6] = {};

	Grid();
	virtual ~Grid();
	void deleteMatchedAndCollectNumber();
	bool checkMatch();
	void fillEmptyGrid();
	void updateGrid(sf::Vector2i, sf::Vector2i);
	void draw(sf::RenderWindow&);
	void swapStone(piece&, piece&);
};

