#include "controller.h"
#include "XF/xf.h"
#include "XF/xfevent.h"

Controller::Controller()
{
    digClock = new DigitalClock(this);
    anim1 = new Animation1(this);
}

void Controller::initialize()
{
  /*  state = ST_WAIT;
    XFEvent* ev = new XFEvent();
    ev->setID(evAnim1);
    ev->setTarget(this);
    XF::getInstance().pushEvent(ev);*/
}

void Controller::initRelations(Data* data)
{
    this->pData = data;
}

bool Controller::processEvent(XFEvent *ev){
/*    bool retval = false;
    CSTATE oldState = state;

    //transition switch
    switch (state)
    {
    case ST_WAIT:
        if (ev->getID() == evAnim1)
        {
            state = ST_ANIM1;
        }
        break;
    case ST_ANIM1:
        if(ev->getID() == evWait1){
            state = ST_WAIT1;
        }
        break;
    case ST_WAIT1:
        if(ev->getID() == evTimeout1){
            state = ST_ANIM1;
        }
        break;
    }

    if (oldState != state)
    {
        //action switch
        switch (state)
        {
        case ST_WAIT:
            ev->setID(evAnim1);
            ev->setTarget(this);
            XF::getInstance().pushEvent(ev);
            break;
        case ST_ANIM1:
            anim1->animate();
            ev->setID(evWait1);
            ev->setTarget(this);
            XF::getInstance().pushEvent(ev);
            break;
        case ST_WAIT1:
            ev->setID(evTimeout1);
            ev->setTarget(this);
            ev->setDelay(valueTimer);
            XF::getInstance().pushEvent(ev);
        }
        retval = true;
    }
    return retval;*/
}

//Modifie the value of the timer, used principaly by
//the anime classes
void Controller::setValueTimer(int time){
    valueTimer = time;
}
