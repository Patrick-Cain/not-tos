#pragma once
#include <string>
#include <iostream>
#include"SFML\Graphics.hpp"


class Monster :
	public sf::Sprite
{
	private:
		sf::Texture all_monster_texture;
		std::string kind_string = "";
		

		// const int attribute, race;
		/* Attribute list Fire - 1 Water - 2 Earth - 3 
		Light - 4 Dark - 5 Heart - 6 */
		// int level, exp, cost, hp, attack, recover, skill_level, coldown, coinsvalue;

	public:
		int hp, attribute, attack;
		Monster();
		Monster(int);
		virtual ~Monster();

		int getHp();

		void draw(sf::RenderWindow&);

		// In Battle Functions
		// Exp enemy.receiveAttack(monster1.getAttackToOthers);
		int calAttackToOthers(int, int, int); 
		
};

