#include "Battle.h"

Battle::Battle(bool* clicked, bool* spinning, bool* time_up, int team_id[], int size)
{	
	initBattleBgFrame();
	for (int i = 0; i < 3; i++)
	{
		playerteam[i] = new Monster(team_id[i]);
	}
	initTeamHP();
	initEnemyHp();
	initTime();
	clicked_ptr = clicked;
	time_up_ptr = time_up;
	spinning_ptr = spinning;


}

Battle::~Battle()
{
	// stopping music
	battle_bgm.stop();
	for (int i = 0; i < 3; i++)
	{
		delete playerteam[i];
	}
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
	max_teamhp = 0;
	for (int i = 0; i < 3; i++) {
		max_teamhp += playerteam[i]->getHp();
	}
	current_teamhp = max_teamhp;

	// Hp bar
	heart_t.loadFromFile("images/heart1.png");
	heart.setTexture(heart_t);

	max_hp_bar_length = 425;
	current_hp_bar_length = (float) max_hp_bar_length;
	hp_bar.setSize(sf::Vector2f(max_hp_bar_length, 20));
	hp_bar.setFillColor(sf::Color(233, 91, 60));
	hp_bar.setOutlineColor(sf::Color(48, 26, 13));
	hp_bar.setOutlineThickness(3);

	hp_bar_bg.setSize(sf::Vector2f(max_hp_bar_length, 20));
	hp_bar_bg.setFillColor(sf::Color(0, 0, 0));
	hp_bar_bg.setOutlineColor(sf::Color(48, 26, 13));
	hp_bar_bg.setOutlineThickness(3);
	
	hp_font.loadFromFile("fonts/BOMBARD.ttf");
	hp_text.setFont(hp_font);
	hp_text_string = std::to_string(current_teamhp) + "/" + std::to_string(max_teamhp);
	hp_text.setString(hp_text_string);
	hp_text.setCharacterSize(19);
	hp_text.setFillColor(sf::Color(106, 39, 56));
	hp_text.setStyle(sf::Text::Bold);
}

void Battle::initTime()
{
	max_time = 10;

	max_time_bar_length = 425;

	current_time_bar_length = (float)max_time_bar_length;
	time_bar.setSize(sf::Vector2f(max_time_bar_length, 20));
	time_bar.setFillColor(sf::Color(114, 255, 110));
	time_bar.setOutlineColor(sf::Color(18, 82, 16));
	time_bar.setOutlineThickness(3);

	time_bar_bg.setSize(sf::Vector2f(max_time_bar_length, 20));
	time_bar_bg.setFillColor(sf::Color(0, 0, 0));
	time_bar_bg.setOutlineColor(sf::Color(48, 26, 13));
	time_bar_bg.setOutlineThickness(3);

	time_font.loadFromFile("fonts/BOMBARD.ttf");
	time_text.setFont(time_font);
	time_text_string = std::to_string(time_value) + "/" + std::to_string(max_time);
	time_text.setString(time_text_string);
	time_text.setCharacterSize(19);
	time_text.setFillColor(sf::Color(106, 39, 56));
	time_text.setStyle(sf::Text::Bold);
}

void Battle::initEnemyHp()
{
	max_enemy_hp = enemy1.hp;
	// Hp bar

	max_enemy_hp_bar_length = 140;
	current_enemy_hp_bar_length = (float)max_enemy_hp_bar_length;
	enemy_hp_bar.setSize(sf::Vector2f(max_enemy_hp_bar_length, 10));
	enemy_hp_bar.setFillColor(sf::Color::Red);
	enemy_hp_bar.setOutlineColor(sf::Color(48, 26, 13));
	enemy_hp_bar.setOutlineThickness(3);

	enemy_hp_bar_bg.setSize(sf::Vector2f(max_enemy_hp_bar_length, 10));
	enemy_hp_bar_bg.setFillColor(sf::Color(0, 0, 0));
	enemy_hp_bar_bg.setOutlineColor(sf::Color(48, 26, 13));
	enemy_hp_bar_bg.setOutlineThickness(2);

	enemy_hp_text.setFont(hp_font);
	enemy_hp_text_string = std::to_string(enemy1.hp) + "/" + std::to_string(max_enemy_hp);
	enemy_hp_text.setString(enemy_hp_text_string);
	enemy_hp_text.setCharacterSize(10);
	enemy_hp_text.setFillColor(sf::Color(106, 39, 56));
	enemy_hp_text.setStyle(sf::Text::Bold);
}

int  Battle::getCurrentTeamHP()
{
	return current_teamhp;
}

void Battle::setCurrentTeamHP(int new_teamhp)
{
	if (new_teamhp < 0)
		current_teamhp = 0;
	else
		current_teamhp = new_teamhp;
}

int Battle::getTotalTeamAttack()
{
	int totalatttack = 0; 
	for (int i = 0; i < 3; i++)
	{
		totalatttack += playerteam[i]->calAttackToOthers(1,3,0,0);
	}
	return totalatttack;
}

void Battle::updateTeamHP(bool* launchattack, int* numofstonedeleted, int size)
{
	if (*launchattack) {
		for (int i = 0; i < size; i++) {
			if (i == 2) {
				int hp_earned = numofstonedeleted[i] * 10;
				int new_team_hp = hp_earned + getCurrentTeamHP();
				if (new_team_hp > max_teamhp) {
					setCurrentTeamHP(max_teamhp);
				}
				else {
					setCurrentTeamHP(new_team_hp);
				}
				
			}
			else {
				enemy1.receiveAttack(numofstonedeleted[i] * 5);
			}
		}
		if (enemy1.hp <= 0) {
			enemy_died = true;
		}
		else {
			int attack = enemy1.calAttackToOthers();
			int hp = getCurrentTeamHP();
			setCurrentTeamHP(hp - attack);
		}
		*launchattack = false;
	}
	hp_text_string = std::to_string(current_teamhp) + "/" + std::to_string(max_teamhp);
	hp_text.setString(hp_text_string);
	current_hp_bar_length = (float)current_teamhp / max_teamhp * max_hp_bar_length;
	hp_bar.setSize(sf::Vector2f(current_hp_bar_length, 20));

	enemy_hp_text_string = std::to_string(enemy1.hp) + "/" + std::to_string(max_enemy_hp);
	enemy_hp_text.setString(enemy_hp_text_string);
	current_enemy_hp_bar_length = (float)enemy1.hp / max_enemy_hp * max_enemy_hp_bar_length;
	enemy_hp_bar.setSize(sf::Vector2f(current_enemy_hp_bar_length, 10));
}

void Battle::updateTime(bool* time_up, bool clicked)
{
	
	if (*clicked_ptr && *spinning_ptr) {
		time_value = 10 - clock.getElapsedTime().asSeconds();
	}
	else {
		clock.restart();
		time_value = 10;
	}

	time_text_string = std::to_string((int)time_value) + "s/" + std::to_string(max_time) + +"s";
	time_text.setString(time_text_string);

	current_time_bar_length = time_value / max_time * max_time_bar_length;
	time_bar.setSize(sf::Vector2f(current_time_bar_length, 20));

	if (time_value < 0 && !(*time_up))
	{
		clock.restart();
		time_value = 10;
		*time_up = true;
	}
}

void Battle::drawall(sf::RenderWindow& window)
{
	// Render battle bg
	//battle_bg.setPosition(-40, -20);
	battle_bg.setPosition(0, 20);
	window.draw(battle_bg);

	// Render hp bar
	hp_bar_bg.setPosition(17, 355);
	window.draw(hp_bar_bg);
	hp_bar.setPosition(17, 355);
	window.draw(hp_bar);
	heart.setPosition(5, 350);
	window.draw(heart);
	hp_text.setPosition(350, 352);
	window.draw(hp_text);


	//Render Time bar
	if (*clicked_ptr && !(*time_up_ptr) && *spinning_ptr) {
		time_bar_bg.setPosition(17, 355);
		window.draw(time_bar_bg);

		time_bar.setPosition(17, 355);
		window.draw(time_bar);

		time.setPosition(5, 350);
		window.draw(time);

		time_text.setPosition(350, 352);
		window.draw(time_text);
	}
	

	// Render upper and lower frame
	battle_uppper_frame.setPosition(-2, 0);
	battle_lower_frame.setPosition(0, 755);
	window.draw(battle_uppper_frame);
	window.draw(battle_lower_frame);

	// Render all the monster
	for (int i = 0; i < 3; i++) {
		playerteam[i]->setPosition(i * 65 , 280);
		window.draw(*playerteam[i]);
	}
	

	// Render all the enemy
	if (!enemy_died) {
		// Render enemy hp bar
		enemy_hp_bar_bg.setPosition(160, 180);
		window.draw(enemy_hp_bar_bg);
		enemy_hp_bar.setPosition(160, 180);
		window.draw(enemy_hp_bar);
		enemy_hp_text.setPosition(260, 178);
		window.draw(enemy_hp_text);

		enemy1.setPosition(188, 200);
		enemy1.draw(window);
	}
	

}

void Battle::playmusic()
{
	battle_bgm.openFromFile("music/battle.wav");
	battle_bgm.play();
}
