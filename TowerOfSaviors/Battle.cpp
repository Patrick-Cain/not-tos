#include "Battle.h"

Battle::Battle() :  monster1(1),monster2(0)
{
	// Loading texture
	battle_bg_t.loadFromFile("images/battle_bg_1.png");
	battle_uppper_frame_t.loadFromFile("images/battle_uppper_frame_1.jpg");
	battle_lower_frame_t.loadFromFile("images/battle_lower_frame_1.jpg");
	battle_bg.setTexture(battle_bg_t);
	battle_uppper_frame.setTexture(battle_uppper_frame_t);
	battle_lower_frame.setTexture(battle_lower_frame_t);

	// Hp bar
	heart_t.loadFromFile("images/heart1.png");
	heart.setTexture(heart_t);
	hp_bar.setSize(sf::Vector2f(425, 20));
	hp_bar.setFillColor(sf::Color(233, 91, 60));
	hp_bar.setOutlineColor(sf::Color(48, 26, 13));
	hp_bar.setOutlineThickness(3);
	hp_font.loadFromFile("fonts/BOMBARD.ttf");
	hp_text.setFont(hp_font);
	hp_text.setString("1000/1000");
	hp_text.setCharacterSize(19);
	hp_text.setFillColor(sf::Color(106, 39, 56));
	hp_text.setStyle(sf::Text::Bold);
}

Battle::~Battle()
{
	// stopping music
	battle_bgm.stop();
}

void Battle::drawall(sf::RenderWindow& window)
{
	// Render battle bg
	//battle_bg.setPosition(-40, -20);
	battle_bg.setPosition(0, 20);
	window.draw(battle_bg);

	// Render hp bar
	hp_bar.setPosition(17, 355);
	window.draw(hp_bar);
	heart.setPosition(5, 350);
	window.draw(heart);
	hp_text.setPosition(360, 352);
	window.draw(hp_text);


	// Render upper and lower frame
	battle_uppper_frame.setPosition(-2, 0);
	battle_lower_frame.setPosition(0, 755);
	window.draw(battle_uppper_frame);
	window.draw(battle_lower_frame);

	// Render all the monster
	monster1.setPosition(175,210);
	window.draw(monster1);
	monster2.setPosition(0, 280);
	window.draw(monster2);

	// Render all the enemy
}

void Battle::drawTeamHP()
{
}

void Battle::playmusic()
{
	battle_bgm.openFromFile("music/battle.wav");
	battle_bgm.play();
}
