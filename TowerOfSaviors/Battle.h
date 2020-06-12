#pragma once
#include<string>  

#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"Monster.h"
#include"Enemy.h"
#include <iostream>

class Battle
{
	private:
		// Texture for battle
		sf::Texture battle_bg_t, battle_uppper_frame_t, battle_lower_frame_t, heart_t, timebar_t;
		sf::Sprite battle_bg, battle_uppper_frame, battle_lower_frame, heart, time;
		
		bool* clicked_ptr;
		bool* time_up_ptr;
		bool* spinning_ptr;

		// Health bar
		sf::RectangleShape hp_bar,hp_bar_bg;
		sf::Font hp_font;
		sf::Text hp_text;
		std::string hp_text_string;
		int max_teamhp, max_hp_bar_length, current_teamhp;
		float current_hp_bar_length;
		bool enemy_died = false;

		// Enemy Health Bar
		sf::RectangleShape enemy_hp_bar, enemy_hp_bar_bg; //
		sf::Text enemy_hp_text;
		std::string enemy_hp_text_string;
		int max_enemy_hp, max_enemy_hp_bar_length;
		float current_enemy_hp_bar_length;



		// Time bar
		sf::Clock clock;
		sf::RectangleShape time_bar, time_bar_bg;
		sf::Font time_font;
		sf::Text time_text;
		std::string time_text_string;
		int max_time, max_time_bar_length, current_time;
		float current_time_bar_length, time_value;

		// Music for battle 
		sf::Music battle_bgm;

		// Monsters initialization
		Monster* playerteam[3];
		Enemy enemy1;

	public:
		Battle(bool*, bool*, bool*, int arr[], int);
		virtual ~Battle();

		void initBattleBgFrame();
		void initTeamHP();
		void initTime();
		void initEnemyHp();

		int getCurrentTeamHP();
		void setCurrentTeamHP(int);

		void updateTeamHP(bool*, int*, int);
		void updateTime(bool*);

		void drawall(sf::RenderWindow&);

		void playmusic();
		
};

