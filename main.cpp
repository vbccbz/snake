#include <conio.h> // _kbhit() _getch()
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include <iostream>

class TimeGame
{
private:
	float seconds;// seconds converted from clock ticks from CPU

public:
	TimeGame(void)
	{
		update();
	}
	void update(void) // update the rawtime and flags
	{
		seconds = clock() / static_cast <float> (CLOCKS_PER_SEC);
	}
	float getElapsedSeconds(void)
	{
		return float((clock() / static_cast <float> (CLOCKS_PER_SEC)) - seconds);
	}
	float getElapsedSecondsUpdate(void)
	{
		float tmp(seconds);
		seconds = clock() / static_cast <float> (CLOCKS_PER_SEC);
		return float(seconds - tmp);
	}
};
class Window {
private:
	int tick;

public:
	char buffer[1000];
	Window(void)
	{
		memset(buffer, '.', 100);
		tick = 0;
	}
	~Window(void)
	{
		;
	}
	void display(void)
	{
		//std::cout << "tick " << tick << '\n';
		//tick += 1;

		for (size_t row = 0; row < 10; ++row)
		{
			for (size_t column = 0; column < 10; ++column)
			{
				std::cout << buffer[row * 10 + column];
			};
			std::cout << '\n';
		}

		//Sleep(100); // flickering (
	}
	void clear(void) {
		system("cls");
	}
	void draw(void) {
		;
	}
};
class Keyboard {
private:

public:
	enum class keys {
		left,
		right,
		up,
		down,
		any,
		esc,
		none
	} key;
	Keyboard(void)
	{
		key = keys::none;
	}
	~Keyboard(void)
	{
		;
	}
	void input(void)
	{
		if (_kbhit()) {
			char ch = _getch();
			switch (ch) {
			case 'w':
				key = keys::up;
				break;
			case 's':
				key = keys::down;
				break;
			case 'a':
				key = keys::left;
				break;
			case 'd':
				key = keys::right;
				break;
			case 27: // ESC
				key = keys::esc;
				break;
			default:
				key = keys::any;
				break;
			}
		}
		else {
			key = keys::none;
		}
	}
};
class World {
public:
	char* table;
	size_t weight;
	size_t height;

public:
	World(size_t w, size_t h)
		: weight(w)
		, height(h)
	{
		table = new char[weight * height];
		memset(table, '-', weight * height);
	}
	~World(void)
	{
		delete[] table;
	}
	void draw(Window& window)
	{
		for (size_t i = 0; i < 100; i++) {
			window.buffer[i] = table[i];
		}
	}
};
class Snake {
	friend class Window;

private:
	struct element {
		struct coordinate {
			int row;
			int column;
		} position;
		int number;
	};
	element body[100];
	size_t length;
	enum class direction {
		left,
		right,
		up,
		down
	} direction;

public:
	Snake(World& world)
	{
		for (size_t element = 0; element < 100; element++) {
			body[element].position.row = -1;
			body[element].position.column = -1;
			body[element].number = element;
		}
		direction = direction::right;
		length = 1;
		// length = 2;
		body[0].number = 0;
		// body[1].number = 1;
		body[0].position.row = 5;
		// body[1].position.row = 5;
		body[0].position.column = 5;
		// body[1].position.column = 4;

#ifdef DEBUG
		length = 5;
		body[0].number = 0;
		body[1].number = 1;
		body[2].number = 2;
		body[3].number = 3;
		body[4].number = 4;

		body[0].position.row = 5;
		body[1].position.row = 5;
		body[2].position.row = 5;
		body[3].position.row = 5;
		body[4].position.row = 5;

		body[0].position.column = 5;
		body[1].position.column = 4;
		body[2].position.column = 3;
		body[3].position.column = 2;
		body[4].position.column = 1;
#endif
		world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
		for (size_t element = 1; element < length; element++) {
			world
				.table[body[element].position.row * 10 + body[element].position.column]
				= 's';
		}

		return;
	};
	~Snake(void)
	{
		;
	}
	void setDirection(Keyboard::keys& key)
	{
		switch (key)
		{
		case Keyboard::keys::up:
			direction = direction::up;
			break;
		case Keyboard::keys::down:
			direction = direction::down;
			break;
		case Keyboard::keys::left:
			direction = direction::left;
			break;
		case Keyboard::keys::right:
			direction = direction::right;
			break;
		case Keyboard::keys::none:
			break;
		case Keyboard::keys::any:
			break;
		}
	}
	void move(World& world)
	{
		// set head position
		element temp = body[0];
		switch (direction)
		{
		case direction::up:
			temp.position.row -= 1;
			if (temp.position.row < 0) {
				temp.position.row = 9;
			}
			break;
		case direction::down:
			temp.position.row += 1;
			if (temp.position.row > 9) {
				temp.position.row = 0;
			}
			break;
		case direction::left:
			temp.position.column -= 1;
			if (temp.position.column < 0) {
				temp.position.column = 9;
			}
			break;
		case direction::right:
			temp.position.column += 1;
			if (temp.position.column > 9) {
				temp.position.column = 0;
			}
			break;
		default:
			break;
		}

		// interacting with world
		switch (world.table[temp.position.row * 10 + temp.position.column])
		{
		case '-':
			// clear
			world.table[body[length - 1].position.row * 10 + body[length - 1].position.column] = '-';

			update();
			body[0].position = temp.position;

			world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
			for (size_t element = 1; element < length; element++) {
				world.table[body[element].position.row * 10 + body[element].position.column] = 's';
			}

			break;

		case '$':
			// no clear

			length += 1;
			update();
			body[0].position = temp.position;

			world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
			for (size_t element = 1; element < length; element++) {
				world.table[body[element].position.row * 10 + body[element].position.column] = 's';
			}

			break;

		case 's':
			// clear
			for (size_t element = 0; element < length; element++) {
				world.table[body[element].position.row * 10 + body[element].position.column] = '-';
			}

			// find intersection
			for (size_t element = 1; element < length; element++) {
				if (temp.position.row == body[element].position.row && temp.position.column == body[element].position.column) {
					length = body[element].number + 1;
				}
			}

			update();
			body[0].position = temp.position;

			world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
			for (size_t element = 1; element < length; element++) {
				world.table[body[element].position.row * 10 + body[element].position.column] = 's';
			}

			break;

		default:

			break;
		}

	}
	//void Snake::write(World& world)
	//{
	//}

private:
	void update(void)
	{
		element temp1, temp2;
		temp1.position = body[0].position;
		for (size_t element = 1; element < length; ++element) {
			temp2.position = body[element].position;
			body[element].position = temp1.position;
			temp1.position = temp2.position;
		}
	}
};
class Fruit {
private:
	struct element {
		struct coordinate {
			int row;
			int column;
		} position;
	} body;
	bool life;

public:
	Fruit(World& world)
	{
		// srand(time(NULL));
		// body.position.column = rand() % 10;
		// body.position.row = rand() % 10;

		body.position.row = 4;
		body.position.column = 5;
		world.table[body.position.row * 10 + body.position.column] = '$';
	}
	~Fruit(void)
	{
		;
	}
	void  generate(World& world)
	{
		// srand(time(NULL));

		// в данном стиле если фрукт появится на столе под змейкой, то змейка затрёт
		// его своими элементами и на следующем цикле условие сгенерирует новый фрукт
		// поэтому лучше заранее этот случай заблокировать
		if (world.table[body.position.row * 10 + body.position.column] != '$') {
			while (world.table[body.position.row * 10 + body.position.column] == 's' || world.table[body.position.row * 10 + body.position.column] == 'S') {
				body.position.column = rand() % 10;
				body.position.row = rand() % 10;
			}
			world.table[body.position.row * 10 + body.position.column] = '$';
		}
	}
	void  generate(void)
	{
		// srand(time(NULL));
		body.position.row = rand() % 10;
		body.position.column = rand() % 10;
		life = true;
	}
	//bool isCollide(snake, fruit)
	//{
	//	
	//}

};

int main(void)
{
	TimeGame tg;
	Keyboard keyboard;
	Window window;

	World world(10, 10);
	Snake snake(world);
	Fruit fruit(world);

	float timer = 0;
	float delay = 0.15;

	while (1)
	{
		keyboard.input();

		if (keyboard.key == Keyboard::keys::esc)
		{
			system("cls");
			std::cout << "Bye!";
			Sleep(100);
			return 0;
		}

		snake.setDirection(keyboard.key);

		float elapsed = tg.getElapsedSecondsUpdate();
		timer += elapsed;
		if (timer >= delay)
		{
			timer = 0;

			snake.move(world);

			//if ( isCollide(snake, fruit) )
			//{
			//	fruit.generate(world);
			//}

			fruit.generate(world);

			//// Если за генерацию фрукта отвечает сам фрукт:
			//// выглядит логичнее;
			//// есть необходимость вызова генерации в главном цикле;
			//// фрукт обязан каждый раз проверять факт существования фрукта;
			//// Если за генерацию фрукта отвечает змейка:
			//// новый фрукт появляется в том же кадре, что и поглощение старого фрукта;
			//// фрукт не обязан проверять факт существования фрукта;
			//// нет необходимости вызова генерации в главном цикле;
			//// Второй способ позволяет запретить змейке доступ ко фрукту, но всё равно
			//// остаётся проблема того, что змейка поглощением изменяет состояние фрукта,
			//// а значит должна иметь доступ к его данным.

		}

		window.clear();

		world.draw(window);
		//window.draw(world); // world.draw(window); ?

		window.display();
	}
	return 0;
}
