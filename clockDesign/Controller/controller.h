#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model\data.h"
#include "XF/ism.h"
#include "digitalclock.h"
#include "animation1.h"

class DigitalClock;
class Animation1;

class Controller: public ISM
{
public:
    enum CEVENT {evAnim1,evWait1,evTimeout1,evDone};
    enum CSTATE {ST_WAIT,ST_ANIM1,ST_WAIT1};

    Controller();
    void initialize();
    void initRelations(Data* data);
    bool processEvent(XFEvent *ev);
    void setValueTimer(int time);

    Data* pData;
    DigitalClock* digClock;
    Animation1* anim1;
int valueTimer = 50;
private:
    CSTATE state;

};

#endif // CONTROLLER_H
