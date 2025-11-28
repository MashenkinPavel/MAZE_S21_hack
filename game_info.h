#ifndef GAME_INFO
#define GAME_INFO
class Viewer;
#include "Controller.h"
#include "Viewer.h"

class GameClass{
public:
    enum class gamestate{
        START_STAGE,
        INTRO_STAGE, 
        CONTROLLER_STAGE,
        GAME_STAGE,
        END_STAGE
    } state;
    void action();
    void init(Controller* joystick);
private:
    Controller* pt_joystick;
    Viewer * pt_viewer; 
    int step = 0;
};



#endif
