#pragma once
#include"SFML\Graphics.hpp"

class Monster :
	public sf::Sprite
{
	private:
		sf::Texture all_monster_texture;

		const int attribute, race;
		/* Attribute list Fire - 1 Water - 2 Earth - 3 
		Light - 4 Dark - 5 Heart - 6 */
		int level, exp, cost, hp, attack, recover, skill_level, coldown, coinsvalue;
		int currenthp;

	public:
		Monster(int);
		virtual ~Monster();

		void draw(sf::RenderWindow&);

		// In Battle Functions
		// Exp enemy.receiveAttack(monster1.getAttackToOthers);
		int getAttackToOthers(int, int, int, int); 
		virtual void receiveAttack(int);
		
};

