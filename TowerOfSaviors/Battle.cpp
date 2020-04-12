#include "Battle.h"

Battle::Battle(int number) : playerteam{Monster(1), Monster(0)}
{	
	initBattleBgFrame();
	max_teamhp = 9999;
	current_teamhp = max_teamhp;
	initTeamHP();
}

Battle::~Battle()
{
	// stopping music
	battle_bgm.stop();
}

void Battle::initBattleBgFrame()
{
	// Loading texture
	battle_bg_t.loadFromFile("images/battle_bg_1.png");
	battle_uppper_frame_t.loadFromFile("images/battle_uppper_frame_1.jpg");
	battle_lower_frame_t.loadFromFile("images/battle_lower_frame_1.jpg");
	battle_bg.setTexture(battle_bg_t);
	battle_uppper_frame.setTexture(battle_uppper_frame_t);
	battle_lower_frame.setTexture(battle_lower_frame_t);
}

void Battle:: initTeamHP()
{
	// Hp bar
	heart_t.loadFromFile("images/heart1.png");
	heart.setTexture(heart_t);

	max_hp_bar_length = 425;
	current_hp_bar_length = (float) max_hp_bar_length;
	hp_bar.setSize(sf::Vector2f(max_hp_bar_length, 20));
	hp_bar.setFillColor(sf::Color(233, 91, 60));
	hp_bar.setOutlineColor(sf::Color(48, 26, 13));
	hp_bar.setOutlineThickness(3);
	
	hp_font.loadFromFile("fonts/BOMBARD.ttf");
	hp_text.setFont(hp_font);
	hp_text_string = std::to_string(current_teamhp) + "/" + std::to_string(max_teamhp);
	hp_text.setString(hp_text_string);
	hp_text.setCharacterSize(19);
	hp_text.setFillColor(sf::Color(106, 39, 56));
	hp_text.setStyle(sf::Text::Bold);
}

void Battle::setCurrentTeamHP(int new_teamhp)
{
	current_teamhp = new_teamhp;
}

void Battle::updateTeamHP()
{
	hp_text_string = std::to_string(current_teamhp) + "/" + std::to_string(max_teamhp);
	hp_text.setString(hp_text_string);
	current_hp_bar_length = (float)current_teamhp / max_teamhp * max_hp_bar_length;
	hp_bar.setSize(sf::Vector2f(current_hp_bar_length, 20));
}

void Battle::drawall(sf::RenderWindow& window)
{
	// Render battle bg
	//battle_bg.setPosition(-40, -20);
	battle_bg.setPosition(0, 20);
	window.draw(battle_bg);

	// Render hp bar
	updateTeamHP();
	hp_bar.setPosition(17, 355);
	window.draw(hp_bar);
	heart.setPosition(5, 350);
	window.draw(heart);
	hp_text.setPosition(350, 352);
	window.draw(hp_text);

	// Render upper and lower frame
	battle_uppper_frame.setPosition(-2, 0);
	battle_lower_frame.setPosition(0, 755);
	window.draw(battle_uppper_frame);
	window.draw(battle_lower_frame);

	// Render all the monster
	playerteam[0].setPosition(175,210);
	window.draw(playerteam[0]);
	playerteam[1].setPosition(0, 280);
	window.draw(playerteam[1]);

	// Render all the enemy
}

void Battle::playmusic()
{
	battle_bgm.openFromFile("music/battle.wav");
	battle_bgm.play();
}
