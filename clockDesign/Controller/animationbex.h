#ifndef ANIMATIONBEX_H
#define ANIMATIONBEX_H

#include "controller.h"

class Controller;

class AnimationBex
{
public:
    enum STATE {ST_INIT, ST_START, ST_BEX, ST_END};
    AnimationBex(Controller* host);
    void animate();
    bool isDone();
    void setIsDone(bool isDone);

private:
    Controller* host;
    STATE state;
    int column;
    bool animDone;
};

#endif // ANIMATIONBEX_H
