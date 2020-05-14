#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	// Создаем окно размером 600 на 600 и частотой обновления 60 кадров в секунду
	sf::RenderWindow window(sf::VideoMode(600, 600), "15");
	window.setFramerateLimit(60);

	sf::Font font;
	font.loadFromFile("calibri.ttf");

	// Текст с обозначением клавиш
	sf::Text text("F2 - New Game / Esc - Exit / Arrow Keys - Move Tile", font, 20);
	text.setFillColor(sf::Color::Cyan);
	text.setPosition(5.f, 5.f);

	// Создаем объект игры
	Game game;
	game.setPosition(50.f, 50.f);

	sf::Event event;
	int move_counter = 0;	// Счетчик случайных ходов для перемешивания головоломки

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// Получаем нажатую клавишу - выполняем соответствующее действие
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Left) game.Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) game.Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Up) game.Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) game.Move(Direction::Down);
				// Новая игра
				if (event.key.code == sf::Keyboard::F2)
				{
					game.Init();
					move_counter = 100;
				}
			}
		}

		// Если счетчик ходов больше нуля, продолжаем перемешивать головоломку
		if (move_counter-- > 0) game.Move((Direction)(rand() % 4));

		// Выполняем необходимые действия по отрисовке
		window.clear();
		window.draw(game);
		window.draw(text);
		window.display();
	}

	return 0;
}