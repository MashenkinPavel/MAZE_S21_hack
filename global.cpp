#include "global.h"
#include <Arduboy2.h>


extern Arduboy2 arduboy;

void waitForButtonPress() {
  // Ждем, пока не будет нажата любая кнопка
  while (!arduboy.buttonsState()) {
    // Обновляем состояние кнопок (в Arduboy2 это делается через вызов pollButtons)
    arduboy.pollButtons();
  }
}