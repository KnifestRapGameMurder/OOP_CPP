#include "Game.h"

Game::Game()
{
	// Подгружаем шрифт для отрисовки элементов
	font.loadFromFile("calibri.ttf");
	Init();
}

void Game::Init()
{
	// Заполняем массив плашек
	for (int i = 0; i < ARRAY_SIZE - 1; i++) elements[i] = i + 1;
	// Ставим пустую плашку в правую нижнюю позицию
	empty_index = ARRAY_SIZE - 1;
	elements[empty_index] = 0;	// Пустая плашка имеет значение = 0
	solved = true;
}

bool Game::Check()
{
	// Проверка собранности головоломки
	for (unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		if (elements[i] > 0 && elements[i] != i + 1) return false;
	}
	return true;
}

void Game::Move(Direction direction)
{
	// Вычисляем строку и колонку пустой плашки
	int col = empty_index % SIZE;
	int row = empty_index / SIZE;

	// Проверка на возможность перемещения и вычисление индекса перемещаемой плашки
	int move_index = -1;
	if (direction == Direction::Left && col < (SIZE - 1)) move_index = empty_index + 1;
	if (direction == Direction::Right && col > 0) move_index = empty_index - 1;
	if (direction == Direction::Up && row < (SIZE - 1)) move_index = empty_index + SIZE;
	if (direction == Direction::Down && row > 0) move_index = empty_index - SIZE;

	// Перемещение плашки на место пустой
	if (empty_index >= 0 && move_index >= 0)
	{
		int tmp = elements[empty_index];
		elements[empty_index] = elements[move_index];
		elements[move_index] = tmp;
		empty_index = move_index;
	}
	solved = Check();
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	sf::Color color = sf::Color(200, 100, 200);

	// Рисуем рамку игрового поля
	sf::RectangleShape shape(sf::Vector2f(FIELD_SIZE, FIELD_SIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	target.draw(shape, states);

	// Подготавливаем рамку для отрисовки всех плашек
	shape.setSize(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	// Подготавливаем текстовую заготовку для отрисовки номеров плашек
	sf::Text text("", font, 52);

	for (unsigned int i = 0; i < ARRAY_SIZE; i++)
	{
		shape.setOutlineColor(color);
		text.setFillColor(color);
		text.setString(std::to_string(elements[i]));
		if (solved)
		{
			// Решенную головоломку выделяем другим цветом
			shape.setOutlineColor(sf::Color::Cyan);
			text.setFillColor(sf::Color::Cyan);
		}
		else if (elements[i] == i + 1)
		{
			// Номера плашек на своих местах выделяем цветом
			text.setFillColor(sf::Color::Green);
		}

		// Рисуем все плашки, кроме пустой
		if (elements[i] > 0)
		{
			// Вычисление позиции плашки для отрисовки
			sf::Vector2f position(i % SIZE * CELL_SIZE + 10.f, i / SIZE * CELL_SIZE + 10.f);
			shape.setPosition(position);
			// Позицию текста подбирал вручную
			text.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
			target.draw(shape, states);
			target.draw(text, states);
		}
	}
}