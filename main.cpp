#include <iostream>
#include <string.h>
#include <windows.h>

class Window {
 private:
  int tick;

 public:
  Window(void);
  ~Window(void);
  char buffer[1000];
  void draw(void);
};

Window::Window(void) {
  memset(buffer, '.', 100);
  tick = 0;
}
Window::~Window(void) { ; }

void Window::draw(void) {
#ifdef DEBUG
  std::cout << "tick " << tick << '\n';
  tick += 1;
#endif

  //std::cout << "Score: " << '\n'; 

  for (size_t row = 0; row < 10; ++row) {
    for (size_t column = 0; column < 10; ++column) {
      std::cout << buffer[row * 10 + column];
    };
    std::cout << '\n';
  }

#ifdef DEBUG
  Sleep(1000);
#endif
#ifndef DEBUG
  Sleep(100);
  system("cls");
#endif

  return;
}

#include <conio.h> // _kbhit() _getch()

class Keyboard {
 public:
  Keyboard();
  ~Keyboard();

  enum class keys { left, right, up, down, any, esc, none };
  keys key;  //???????????????????? Why can't go before?

  void input(void);  ///////////???????? Keyboard::key ?

 private:
};

Keyboard::Keyboard(void) { key = keys::none; }

Keyboard::~Keyboard(void) {}

void Keyboard::input(void) {  ////////////?
  if (_kbhit()) {
    switch (_getch()) {
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
      case 27: //case 'ESC':
        key = keys::esc;
        break;
      default:
        key = keys::any;
        break;
    }
  } else {
    key = keys::none;
  }
  return;
}

#include <string.h>

class World {
 public:
  World();
  ~World();
  char table[100];
  void write(Window& window);
 private:
};

World::World(void) { 
  memset(table, '-', 100); 
}

World::~World(void) {}

void World::write(Window& window) {
  for (size_t i = 0; i < 100; i++) {
    window.buffer[i] = table[i];
  }
  return;
}




#include <string.h>
#include <iostream>
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
  enum class direction { left, right, up, down } direction;

 public:
  Snake(World & world);
  ~Snake(void);

  void move(Keyboard::keys &key, World &world);

 private:
  void update(void);
};

Snake::Snake(World& world) {
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
    world.table[body[element].position.row * 10 + body[element].position.column] = 's';
  }

  return;
};

Snake::~Snake(void) {}

void Snake::move(Keyboard::keys& key, World& world) {
  switch (key) {
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

  element temp = body[0];

  switch (direction) {
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

  switch (world.table[temp.position.row * 10 + temp.position.column]) {
    case '-':
      // clear
      world.table[body[length - 1].position.row * 10 +
                  body[length - 1].position.column] = '-';

      update();
      body[0].position = temp.position;

      world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
      for (size_t element = 1; element < length; element++) {
        world.table[body[element].position.row * 10 +
                    body[element].position.column] = 's';
      }

      break;

    case '$':
      // no clear

      length += 1;
      update();
      body[0].position = temp.position;

      world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
      for (size_t element = 1; element < length; element++) {
        world.table[body[element].position.row * 10 +
                    body[element].position.column] = 's';
      }

      break;

    case 's':
      // clear
      for (size_t element = 0; element < length; element++) {
        world.table[body[element].position.row * 10 +
                    body[element].position.column] = '-';
      }
  
      // find intersection
      for (size_t element = 1; element < length; element++) {
        if (temp.position.row == body[element].position.row &&
            temp.position.column == body[element].position.column) {
          length = body[element].number + 1;
        }
      }

      update();
      body[0].position = temp.position;

      world.table[body[0].position.row * 10 + body[0].position.column] = 'S';
      for (size_t element = 1; element < length; element++) {
        world.table[body[element].position.row * 10 +
                    body[element].position.column] = 's';
      }

      break;

    default:

      break;
  }

  return;
}

void Snake::update(void) {
  element temp1, temp2;
  temp1.position = body[0].position;
  for (size_t element = 1; element < length; ++element) {  
    temp2.position = body[element].position;
    body[element].position = temp1.position;
    temp1.position = temp2.position;
  }
}


#include <stdlib.h>
#include <time.h>

class Fruit {
 public:
  Fruit(World& world);
  ~Fruit(void);
  void generate(void);
  void generate(World& world);
  void write(Window & window);
 private:
  struct element {
    struct coordinate {
      int row;
      int column;
    } position;
  } body;
};

Fruit::Fruit(World& world) {
  // srand(time(NULL));
  //body.position.column = rand() % 10;
  //body.position.row = rand() % 10;

  body.position.row = 4;
  body.position.column = 5;
  world.table[body.position.row * 10 + body.position.column] = '$';
}

Fruit::~Fruit(void) {}

void Fruit::generate(World & world) {
  // srand(time(NULL));

  // в данном стиле если фрукт появится на столе под змейкой, то змейка затрёт его своими элементами и на следующем цикле условие сгенерирует новый фрукт
  // поэтому лучше заранее этот случай заблокировать
  if (world.table[body.position.row * 10 + body.position.column] != '$') {
    while (world.table[body.position.row * 10 + body.position.column] == 's' ||
           world.table[body.position.row * 10 + body.position.column] == 'S') {
      body.position.column = rand() % 10;
      body.position.row = rand() % 10;
    }
    world.table[body.position.row * 10 + body.position.column] = '$';
  }

  return;
}

int main(void) {
  Keyboard keyboard;
  Window window;

  World world;
  Snake snake(world);
  Fruit fruit(world);

  while ( keyboard.key != Keyboard::keys::esc) {
    keyboard.input();
    fruit.generate(world);
    snake.move(keyboard.key, world);
    world.write(window);

    // Если за генерацию фрукта отвечает змейка:
      // новый фрукт появляется в том же кадре, что и поглощение старого фрукта;
      // фрукт не обязан проверять факт существования фрукта;
      // нет необходимости вызова генерации в главном цикле;
    // Если за генерацию фрукта отвечает сам фрукт:
      // выглядит логичнее;
      // есть необходимость вызова генерации в главном цикле;
      // фрукт обязан каждый раз проверять факт существования фрукта;
    // Второй способ позволяет запретить змейке доступ ко фрукту, но всё равно остаётся проблема того, что змейка поглощением изменяет состояние фрукта, а значит должна иметь доступ к его данным.

    window.draw();
  }
  return 0;
}
