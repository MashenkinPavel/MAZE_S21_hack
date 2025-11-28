#include <Arduboy2.h>

#include "global.h"
#include "game_info.h"

Arduboy2 arduboy;
GameInfo game;

void create_maze(int cols, int rows);

void setup() {
    arduboy.begin();
    arduboy.clear(); // Очистка экрана
    game.init();
}

void loop() {
// Если не обновлять экран постоянно, то прямоугольник будет мигать.
// Вместо этого, обычно рисуют в цикле, но только если экран готов к обновлению.
if (!arduboy.nextFrame())
 arduboy.clear(); // Очищаем буфер экрана

 // Рисуем прямоугольник
 arduboy.drawRect(0, 0, 128, 64, WHITE);
 arduboy.drawRect(0, 0, X_SIZE, Y_SIZE, WHITE);
 
 //create_maze(COLCOUNT, ROWCOUNT);

 //draw_maze();
 //game.draw();
 arduboy.display(); // Выводим буфер на экран
}
