#pragma once
#include <string>
#include <iostream>
#include"SFML\Graphics.hpp"


class Monster :
	public sf::Sprite
{
	private:
		sf::Texture monster_texture;
		std::string kind_string = "";
		
		/* Attribute list Fire - 1 Water - 2 Earth - 3 
		Light - 4 Dark - 5 Heart - 6 */

	public:
		int hp, kind, attack;
		Monster();
		Monster(int, int, int, int);
		virtual ~Monster();

		int getHp();

		void draw(sf::RenderWindow&);

		int calAttackToOthers(int, int); 
		
};

