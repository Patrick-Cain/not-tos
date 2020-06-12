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
	switch (id)
	{
	case 1:
		hp = 100;
		attribute = 4;
		kind_string = "Fire";
		attack = 50;
		break;

	case 2:
		hp = 200;
		attribute = 1;
		kind_string = "Earth";
		attack = 50;
		break;

	case 3:
		hp = 300;
		attribute = 5;
		kind_string = "Light";
		attack = 50;
		break;

	case 4:
		hp = 100;
		attribute = 0;
		kind_string = "Water";
		attack = 50;
		break;

	case 5:
		hp = 100;
		attribute = 3;
		kind_string = "Dark";
		attack = 50;
		break;
	
	case 6:
		hp = 100;
		attribute = 0;
		kind_string = "Water";
		attack = 50;
		break;
	
	case 7:
		hp = 100;
		attribute = 1;
		kind_string = "Earth";
		attack = 50;
		break;
	
	case 8:
		hp = 100;
		attribute = 3;
		kind_string = "Dark";
		attack = 50;
		break;
	
	case 9:
		hp = 100;
		attribute = 5;
		kind_string = "Light";
		attack = 50;
		break;

	default:
		std::cout << "Invalid Team Player Chosen\n";
		break;
	}

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

int Monster::calAttackToOthers(int attribute, int numofb, int combo)
{
	/* Calculate damage inflicted to others*/
	/* Attack Rules:
	more than 3, 1 is 0.25 each, for enchanted is further add 0.15
	combo is 0.25
	*/
	if (attribute == this->attribute && numofb !=0) {
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
