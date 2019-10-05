#ifndef ANIMATION1_H
#define ANIMATION1_H

#include "controller.h"

class Controller;

class Animation1
{
public:
    enum STATE {ST_INIT, ST_START, ST_WAVE, ST_END};
    Animation1(Controller* host);
    void animate();

private:
    Controller* host;
    STATE state;
    int column;
    bool animDone;
};

#endif // ANIMATION1_H
