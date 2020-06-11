#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(int id)
{
	std::string file_path_to_image = "images/" + std::to_string(id) + ".png";
	// Load texture for all monster including inherited
	all_monster_texture.loadFromFile(file_path_to_image);
	this->setTexture(all_monster_texture);
	hp = 100;

}

Monster::~Monster()
{
}

int Monster::getHp()
{
	return hp;
}

void Monster::draw(sf::RenderWindow& window)
{
	window.draw(*this);
}

int Monster::calAttackToOthers(int attribute, int numofb, int numofe, int combo)
{
	/* Calculate damage inflicted to others*/
	/* Attack Rules:
	more than 3, 1 is 0.25 each, for enchanted is further add 0.15
	combo is 0.25
	*/
	/*int newattackmulti = 100 + (numofb + numofe - 3) * 25 + numofe * 15;
	int newattack = attack * newattackmulti / 100;
	int comboeffect = 100 + 25 * combo;
	
	return (newattack * comboeffect / 100 );*/
	return 10;
}

void Monster::receiveAttack(int attack) 
{
	/* Receive attack from enemy and minus the currenthp
	Overrided if from player's monster*/

}
