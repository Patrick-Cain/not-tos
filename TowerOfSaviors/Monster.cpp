#include "Monster.h"

Monster::Monster(const int enorfri) : attribute(1), race(1), hp(4444)
{
	// Load texture for all monster including inherited
	if (enorfri) {
		all_monster_texture.loadFromFile("images/w3.png");
		this->setTexture(all_monster_texture);
	}
	else {
		all_monster_texture.loadFromFile("images/temp2.png");
		this->setTexture(all_monster_texture);
	}
}

Monster::~Monster()
{
}

void Monster::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

int Monster::getAttackToOthers(int attribute, int numofb, int numofe, int combo)
{
	/* Calculate damage inflicted to others*/
	/* Attack Rules:
	more than 3, 1 is 0.25 each, for enchanted is further add 0.15
	combo is 0.25
	*/
	int newattackmulti = 100 + (numofb + numofe - 3) * 25 + numofe * 15;
	int newattack = attack * newattackmulti / 100;
	int comboeffect = 100 + 25 * combo;
	
	return (newattack * comboeffect / 100 );
}

void Monster::receiveAttack(int attack) 
{
	/* Receive attack from enemy and minus the currenthp
	Overrided if from player's monster*/

}
