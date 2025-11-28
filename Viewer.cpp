#include <Arduboy2.h>
#include "Viewer.h"
#include "game_info.h"

extern Arduboy2 arduboy;



void Viewer::update(){
    switch (pt_game->state){
        case GameClass::gamestate::START_STAGE:
        {
            ViewStartScreen();
        }
        break;
        case GameClass::gamestate::INTRO_STAGE:
        {
            ViewIntroScreen();
        }
        break;
    }
}


void Viewer::ViewStartScreen(){
      char text[] = "aMAZEing GAME\n by PixelForge\n";
        arduboy.print(text);
}



void Viewer::ViewIntroScreen(){
      char text[] = "A long time ago in a galaxy far, far away...\n    \
                     Press Button A for continue!";
        arduboy.print(text);
}