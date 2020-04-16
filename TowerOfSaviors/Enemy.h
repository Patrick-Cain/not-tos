#pragma once
#include"SFML\Graphics.hpp"

class Enemy : 
	public sf::Sprite
{
	private:
		int attribute, opp_attribute, attack, cd, hp, defense, lootcoin, lootcard_id;
	protected:
	public:
		Enemy();
		~Enemy();

		void calOppAttribute();
		int calAttackToOthers(int);
		virtual void receiveAttack(int);

};