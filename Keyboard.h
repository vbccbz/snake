#include <conio.h>

#pragma once

class Keyboard {
 public:
  Keyboard();
  ~Keyboard();

  enum class key { 
    left, 
    right, 
    up, 
    down, 
    any,
    esc,
    none } code; //???????????????????? Why can't go after?

  key input(void);///////////???????? Keyboard::key ?
  
 private:

};
