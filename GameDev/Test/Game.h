#pragma once

#include"Window.h"

class Game;

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();

	sf::Time GetElapsed();
	void RestartClock();
	
private:
	void MoveMushroom();
	Window m_window;
	sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Vector2i m_increment;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};
