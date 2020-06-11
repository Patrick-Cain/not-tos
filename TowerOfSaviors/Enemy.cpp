#include "Enemy.h"

Enemy::Enemy()
{
	enemy_texture.loadFromFile("images/w3.png");
	this->setTexture(enemy_texture);
	hp = 100;
}

Enemy::~Enemy()
{
}


int Enemy::calAttackToOthers()
{
	return 20;
}

void Enemy::receiveAttack(int attack)
{
	hp -= attack;
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}
