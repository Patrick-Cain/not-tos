#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(int id, int hp, int attack, int kind)
{
	std::string kind_string_arr[6] = {"Water", "Earth", "Heart", "Dark", "Fire", "Light"};
	std::string file_path_to_image = "images/" + std::to_string(id) + ".png";
	monster_texture.loadFromFile(file_path_to_image);
	this->setTexture(monster_texture);
	this->hp = hp;
	this->attack = attack;
	this->kind = kind;
	this->kind_string = kind_string_arr[kind];
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

int Monster::calAttackToOthers(int attribute, int numofb)
{
	/* Calculate damage inflicted to others*/
	/* Attack Rules:
	more than 3, 1 is 0.25 each, for enchanted is further add 0.15
	combo is 0.25
	*/
	if (attribute == this->kind && numofb !=0) {
		int newattackmulti = 100 + (numofb - 3) * 25;
		int newattack = attack * (float)newattackmulti / 100;
		// int comboeffect = 100 + 25 * combo;
		// return (newattack * comboeffect / 100);
		std::cout << "Calculating for " << kind_string << " stone" << "\n";
		std::cout << "Original Player Attack:" << attack << "\n";
		std::cout << "Damaged Done Due to Extra Stone:" << newattack << "\n";
		return (newattack);
	}
	else {
		return 0;
	}
	
}
