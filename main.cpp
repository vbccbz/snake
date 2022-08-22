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
class Sprite
{
public:
	char symbol;
	int row;
	int column;
public:
	Sprite(char s) : symbol(s)
	{
		row = 0;
		column = 0;
	}
	void setPosition(int r, int c)
	{
		row = r; column = c;
	}
	void setSymbol(char ch)
	{
		symbol = ch;
	}
};
class Window {
private:
	//int tick;
public:
	char buffer[100];
	Window(void)
	{
		//tick = 0;
		clear();
	}
	~Window(void)
	{
		;
	}
	void clear(void)
	{
		memset(buffer, '8', 100);
		system("cls");
	}
	void draw(Sprite& s)
	{
		buffer[s.row * 10 + s.column] = s.symbol;
	}
	void display(void)
	{
		//std::cout << "tick " << tick << '\n';
		//tick += 1;

		for (size_t i = 0; i < 100; ++i)
		{
			std::cout << buffer[i];
			if (((i + 1) % 10) == 0)
			{
				std::cout << '\n';
			}
		}
		std::cout << '\n';

		Sleep(50); // flickering (
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
		none,
		p,
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
			case 'p': // ESC
				key = keys::p;
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
class Snake {
private:
	//friend class Window;

public:
	struct element
	{
		struct coordinate
		{
			int row;
			int column;
		} position;
		//int number;
	};
	element body[100];
	size_t length;
	enum class direction {
		left,
		right,
		up,
		down
	} direction;
	int life;
	int hit;
public:
	Snake(void)
	{
		life = 3;
		direction = direction::right;
		int r = 0;
		int c = 5;
		length = 4;
		for (int i = 0; i < length; i++)
		{
			body[i].position.row = r;
			body[i].position.column = c--; //body[c].position.row
		}
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
	//void move(void)
	//{
	//	updateBody();
	//	moveHead();// otherwise the head must be copied
	//}
	//void moveHead(void)
	//{
	//	switch (direction)
	//	{
	//	case direction::up:
	//		body[0].position.row -= 1;
	//		break;
	//	case direction::down:
	//		body[0].position.row += 1;
	//		break;
	//	case direction::left:
	//		body[0].position.column -= 1;
	//		break;
	//	case direction::right:
	//		body[0].position.column += 1;
	//		break;
	//	default:
	//		break;
	//	}
	//}
	void updateBody(void)
	{
		element temp1, temp2;
		temp1.position = body[0].position;
		for (size_t i = 1; i <= length; ++i) {
			temp2.position = body[i].position;
			body[i].position = temp1.position;
			temp1.position = temp2.position;
		}
	}
};
class Fruit {
public:
	struct element
	{
		struct coordinate
		{
			int row;
			int column;
		} position;
	};
	element body;
	//bool life;

public:
	Fruit(void)
	{
		// srand(time(NULL));
		// body.position.row = rand() % 10;
		// body.position.column = rand() % 10;

		body.position.row = 5;
		body.position.column = 5;

		//life = true;
	}
	~Fruit(void)
	{
		;
	}
	void generate(void)
	{
		// srand(time(NULL));
		body.position.row = rand() % 10;
		body.position.column = rand() % 10;
		//life = true;
	}
	//bool lifeState(void)
	//{
	//	return life ? true : false;
	//}
};
bool collide(Snake& s, Fruit& f)
{
	bool result = false;
	if (
		s.body[0].position.column == f.body.position.column &&
		s.body[0].position.row == f.body.position.row)
	{
		result = true;
	}
	return result;
}
bool collide(Snake& s)
{
	bool result = false;
	for (int i = 2; i < s.length; ++i)
	{
		if (s.body[0].position.row == s.body[i].position.row &&
			s.body[0].position.column == s.body[i].position.column)
		{
			result = true;
			s.hit = i;
		}
	}
	return result;
}
int main(void)
{
	Window window;
	Keyboard keyboard;
	TimeGame tg;

	//World world(10, 10);
	//int worldI = 10;
	//int worldJ = 10;

	Sprite sw('-');

	Snake snake;
	Sprite sn('s');

	Fruit fruit;
	Sprite sf('$');

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

		//if (keyboard.key == Keyboard::keys::p)
		//{
		//	Sleep(5000);
		//}

		snake.setDirection(keyboard.key);

		float elapsed = tg.getElapsedSecondsUpdate();
		timer += elapsed;

		if (timer >= delay)
		{
			// reset timer
			timer = 0;

			// body must be update before head
			snake.updateBody();

			// update head and do wrapping
			switch (snake.direction)
			{
			case Snake::Snake::direction::up:
				snake.body[0].position.row -= 1;
				if (snake.body[0].position.row < 0)
				{
					snake.body[0].position.row = 9;
				}
				break;
			case Snake::direction::down:
				snake.body[0].position.row += 1;
				if (snake.body[0].position.row > 9)
				{
					snake.body[0].position.row = 0;
				}
				break;
			case Snake::direction::left:
				snake.body[0].position.column -= 1;
				if (snake.body[0].position.column < 0)
				{
					snake.body[0].position.column = 9;
				}
				break;
			case Snake::direction::right:
				snake.body[0].position.column += 1;
				if (snake.body[0].position.column > 9)
				{
					snake.body[0].position.column = 0;
				}
				break;
			default:
				break;
			}

			// check collision with another object
			if (collide(snake, fruit))
			{
				//Sleep(1000);
				snake.length++;
				fruit.generate();
			}

			// check collision with self
			if (collide(snake))
			{
				snake.length = snake.hit;
				snake.life--;
			}
		}

		window.clear();

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				sw.setPosition(i, j);
				window.draw(sw);
			}
		}

		for (int i = 0; i < snake.length; ++i)
		{
			sn.setPosition(snake.body[i].position.row, snake.body[i].position.column);
			window.draw(sn);
		}

		sf.setPosition(fruit.body.position.row, fruit.body.position.column);
		window.draw(sf);

		std::cout << " life: " << snake.life << '\n';

		window.display();
	}

	return 0;
}
