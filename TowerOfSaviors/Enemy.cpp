#include "Enemy.h"

Enemy::Enemy()
{
	attribute = 1;
	calOppAttribute();
	attack = 1000;
	cd = 3;
	hp = 1000;
	defense = 1000;
	lootcoin = 1000;
	lootcard_id = 1000;
}

Enemy::~Enemy()
{
}

void Enemy::calOppAttribute()
{
}

int Enemy::calAttackToOthers(int attribute)
{
	if (attribute == opp_attribute)
		return attack * 150 / 100;
	return attack;
}

void Enemy::receiveAttack(int attack)
{
	if (attack > defense) {
		hp -= (attack - defense);
	}
	else {
		hp -= 1;
	}
}
