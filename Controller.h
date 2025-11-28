#ifndef CONTROLLER_H
#define CONTROLLER_H
class Controller{
public:
    enum class action{
        NO_ACTION,
        PRESS_UP,
        PRESS_DOWN, 
        PRESS_LEFT,
        PRESS_RIGHT,
        PRESS_A,
        PRESS_B
    } button = action::NO_ACTION;
    void init();
    void get_action();
    Controller::action exec();
};


#endif