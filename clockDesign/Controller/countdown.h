#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include "controller.h"

class Controller;

class Countdown
{
public:
    enum STATE {ST_INIT, ST_COUNT, ST_ANIM};
    Countdown(Controller* host);
    void animate();
    bool isDone();
    void setIsDone(bool isDone);
    void animCountDown();

private:
    Controller* host;
    bool animDone;
    STATE state;
    int countDown;
};

#endif // COUNTDOWN_H
