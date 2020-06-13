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


	public:
		int hp, kind, attack;
		Monster();
		Monster(int, int, int, int);
		virtual ~Monster();
		int getHp();
		void draw(sf::RenderWindow&);
		int calAttackToOthers(int, int); 
		
};

