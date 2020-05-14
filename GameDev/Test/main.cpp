#include"Game.h"

//#define RENDER_RECTANGLE
//#define BOUNCING_sprite1

void main(int argc, char** argv[])
{
#ifdef RENDER_RECTANGLE
	sf::RenderWindow window(sf::VideoMode(640, 480),
		"Rendering the rectangle.");

	//Creating our shape.
	sf::RectangleShape rectangle(sf::Vector2f(128.0f, 128.0f));
	rectangle.setFillColor(sf::Color::Yellow);
	rectangle.setPosition(320, 240);
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);//Center of rectangle

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				//	Close window button clicked
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		window.draw(rectangle);	//	Drawing our shape
		window.display();
	}
#endif // RENDER_RECTANGLE

#ifdef BOUNCING_sprite1
	sf::RenderWindow window(sf::VideoMode(640, 480),
		"Bouncing sprite1.");

	sf::Texture texture1;
	texture1.loadFromFile("texture1.png");
	sf::Sprite sprite1(texture1);
	sf::Vector2u size = texture1.getSize();
	sprite1.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.1f, 0.1f);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if ((sprite1.getPosition().x + (size.x / 2) >
			window.getSize().x&& increment.x > 0) ||
			(sprite1.getPosition().x - (size.x / 2) < 0 &&
				increment.x < 0))
		{
			// Reverse the direction on X axis.
			increment.x = -increment.x;
			//sprite1.setColor(sf::Color(255, 0, 0, 255)); // Red tint.
		}

		if ((sprite1.getPosition().y + (size.y / 2) >
			window.getSize().y&& increment.y > 0) ||
			(sprite1.getPosition().y - (size.y / 2) < 0 &&
				increment.y < 0))
		{
			// Reverse the direction on Y axis.
			increment.y = -increment.y;
			//sprite1.setColor(sf::Color(255, 0, 0, 255)); // Red tint.
		}

		sprite1.setPosition(sprite1.getPosition() + increment);

		window.clear(sf::Color(16, 16, 16, 255));	// Dark grey.
		window.draw(sprite1);
		window.display();
	}

#endif // BOUNCING_sprite1

	
	//Program entry point.
	Game game;	// Creating our game object.
	while (!game.GetWindow()->IsDone())
	{
		// Game loop.
		game.HandleInput();
	}

}