#include <conio.h>
#include <string.h>
#include <windows.h>

#include <iostream>

class Dot {
 public:
  Dot(int c1 = 5, int c2 = 5);
  ~Dot(void);
  friend class Keyboard;
  int get_column(void);
  int get_row(void);
  void print_coordinate(void);

 private:
  int column;
  int row;
};

Dot::Dot(int c1, int c2) {
  column = c1;
  row = c2;
}

Dot::~Dot(void) { ; }

int Dot::get_column(void) { return column; }

int Dot::get_row(void) { return row; }

void Dot::print_coordinate(void) {
  std::cout << "dot" << '\n';
  std::cout << "column = " << column << '\n';
  std::cout << "row = " << row << '\n';
}

class Printer {
 public:
  Printer(void);
  ~Printer(void);
  void write(Dot& dot);
  void print(void);

 private:
  char arr[100];
};

Printer::Printer(void) { memset(arr, '-', 100); }

Printer::~Printer(void) { ; }

void Printer::write(Dot& dot) {
  memset(arr, '-', 100);
  arr[dot.get_row() * 10 + dot.get_column()] = 'X';
  return;
}

void Printer::print(void) {
  for (size_t row = 0; row < 10; ++row) {
    for (size_t column = 0; column < 10; ++column) {
      std::cout << arr[row * 10 + column];
      // Sleep(10);
    };
    std::cout << '\n';
    // Sleep(10);
  }
  Sleep(50);
  system("cls");
  return;
}

class Keyboard {
 public:
  Keyboard();
  ~Keyboard();
  void input(Dot& dot);

 private:
};

Keyboard::Keyboard() {}

Keyboard::~Keyboard() {}

void Keyboard::input(Dot& dot) {
  if (_kbhit()) {
    switch (_getch()) {
      case 'w':
        dot.row -= 1;
        if (dot.row < 0) {
          dot.row = 9;
        }
        break;
      case 's':
        dot.row += 1;
        if (dot.row > 9) {
          dot.row = 0;
        }
        break;
      case 'a':
        dot.column -= 1;
        if (dot.column < 0) {
          dot.column = 9;
        }
        break;
      case 'd':
        dot.column += 1;
        if (dot.column > 9) {
          dot.column = 0;
        }
        break;
      default:
        break;
    }
  }
}

int main(void) {
  Dot dot(5,5);
  Printer printer;
  Keyboard keyboard;
  while (1) {
    keyboard.input(dot);
    printer.write(dot);  // dot.write(arr);
    dot.print_coordinate();
    printer.print();  // printer(arr);
  }
  return 0;
}
