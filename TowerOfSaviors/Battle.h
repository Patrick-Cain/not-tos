#pragma once
#include<string>  

#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"Monster.h"
#include"Enemy.h"

class Battle
{
	private:
		// Texture for battle
		sf::Texture battle_bg_t, battle_uppper_frame_t, battle_lower_frame_t, heart_t;
		sf::Sprite battle_bg, battle_uppper_frame, battle_lower_frame, heart;

		// Health bar
		sf::RectangleShape hp_bar,hp_bar_bg;
		sf::Font hp_font;
		sf::Text hp_text;
		std::string hp_text_string;
		int max_teamhp, max_hp_bar_length, current_teamhp;
		float current_hp_bar_length;

		// Music for battle 
		sf::Music battle_bgm;

		// Monsters initialization
		Monster playerteam[2];
		Enemy enemy1;

	public:
		Battle(int);
		virtual ~Battle();

		void initBattleBgFrame();
		void initTeamHP();

		int getCurrentTeamHP();
		void setCurrentTeamHP(int);
		int getTotalTeamAttack();

		void updateTeamHP();

		void drawall(sf::RenderWindow&);

		void playmusic();
		
};

