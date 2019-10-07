#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model\data.h"
#include "XF/ism.h"
#include "XF/xf.h"
#include "XF/xfevent.h"
#include "digitalclock.h"
#include "animation1.h"

class DigitalClock;
class Animation1;

class Controller: public ISM
{
public:

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
    XF::CSTATE state;

};

#endif // CONTROLLER_H
