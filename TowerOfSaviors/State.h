#pragma once

#include<stack>
#include<iostream>
#include<ctime>
#include<cstdlib>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"

class State
{
	private:
		bool quit = false;

	public:
		State();
		virtual ~State();

		bool getQuit();
		void setQuit();

		virtual void endState() = 0;
		virtual void updateEvent(sf::Event) = 0;
		virtual void update() = 0;
		virtual void render(sf::RenderWindow&) = 0;

};

