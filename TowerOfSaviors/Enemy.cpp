#include "Enemy.h"

Enemy::Enemy()
{
	enemy_texture.loadFromFile("images/w3.png");
	this->setTexture(enemy_texture);
	int id = 1;
	switch (id)
	{
	case 1:
		hp = 300;
		attribute = 0;
		attack = 20;
		break;

	default:
		break;
	}
	
}

Enemy::~Enemy()
{
}


int Enemy::calAttackToOthers()
{
	return attack;
}

void Enemy::receiveAttack(int attack)
{
	hp -= attack;
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}
