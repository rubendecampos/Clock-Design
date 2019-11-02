#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model\data.h"
#include "XF/ism.h"
#include "XF/xf.h"
#include "XF/xfevent.h"
#include "digitalclock.h"
#include "animation1.h"
#include "countdown.h"
#include "letter.h"
#include "View/view.h"
#include "Controller/animationbex.h"

class DigitalClock;
class Animation1;
class Countdown;
class Letter;
class View;
class AnimationBex;

class Controller: public ISM
{
public:

    Controller();
    void initialize();

    //void initRelations(Data *data, View *view);
    void initRelations(Data *data);
    bool processEvent(XFEvent *ev);
    void setValueTimer(int time);

    Data* pData;
    DigitalClock* digClock;
    Animation1* anim1;
    Countdown* countDown;
    Letter* letter;
    AnimationBex* bex;
int valueTimer = 50;
private:
    XF::CSTATE state;

};

#endif // CONTROLLER_H
