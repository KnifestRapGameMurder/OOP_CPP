#pragma once
#include <SFML/Graphics.hpp>

const int SIZE = 4;						// Размер игрового поля в плашках
const int ARRAY_SIZE = SIZE * SIZE;		// Размер массива
const int FIELD_SIZE = 500;				// Размер игрового поля в пикселях
const int CELL_SIZE = 120;				// Размер плашки в пикселях

enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

class Game : public sf::Drawable, public sf::Transformable
{
protected:
	int elements[ARRAY_SIZE];
	int empty_index;
	bool solved;
	sf::Font font;
public:
	Game();
	void Init();
	bool Check();
	void Move(Direction direction);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
