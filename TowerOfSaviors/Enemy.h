#pragma once
#include"SFML\Graphics.hpp"

class Enemy : 
	public sf::Sprite
{
	private:
		sf::Texture enemy_texture;

	public:
		Enemy();
		~Enemy();
		int hp;
		int calAttackToOthers();
		void receiveAttack(int);

		void draw(sf::RenderWindow& window);

};