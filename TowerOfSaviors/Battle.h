#pragma once
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"Monster.h"

class Battle
{
	private:
		// Texture for battle
		sf::Texture battle_bg_t, battle_uppper_frame_t, battle_lower_frame_t, heart_t;
		sf::Sprite battle_bg, battle_uppper_frame, battle_lower_frame, heart;

		// Health bar
		sf::RectangleShape hp_bar;
		sf::Font hp_font;
		sf::Text hp_text;

		// Music for battle 
		sf::Music battle_bgm;

		// Monsters initialization
		Monster monster1, monster2; // should be an array


	public:
		Battle();
		virtual ~Battle();

		void drawall(sf::RenderWindow&);
		void drawTeamHP();

		void playmusic();
		
};

