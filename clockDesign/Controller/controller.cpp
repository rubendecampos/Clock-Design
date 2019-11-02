#include "controller.h"

//Constructor
Controller::Controller()
{
    digClock = new DigitalClock(this);
    anim1 = new Animation1(this);
    countDown = new Countdown(this);
    letter = new Letter(this);
    bex = new AnimationBex(this);
}

//Destructor
void Controller::initialize()
{
    state = XF::ST_WAIT;
}

//Initialize the relation between Controller and Data
void Controller::initRelations(Data* data)
{
    this->pData = data;
}

//Called to process an XF event, contain the main
//state machine
bool Controller::processEvent(XFEvent *ev){
    bool retval = false;
    XF::CSTATE oldState = state;

    //transition switch
    switch (state)
    {
    case XF::ST_WAIT:
        if (ev->getID() == XF::evAnim1)
        {
            state = XF::ST_ANIM1;
        }
        if(ev->getID() == XF::evCountdown){
            state = XF::ST_COUNTDOWN;
        }
        if(ev->getID() == XF::evBeX){
            state = XF::ST_BEX;
        }
        break;
    case XF::ST_ANIM1:
        if(ev->getID() == XF::evWait){
            state = XF::ST_WAIT1;
        }
        if(ev->getID() == XF::evDone){
            state = XF::ST_WAIT;
        }
        break;
    case XF::ST_WAIT1:
        if(ev->getID() == XF::evTimeout){
            state = XF::ST_ANIM1;
        }
        break;
    case XF::ST_COUNTDOWN:
        if(ev->getID() == XF::evWait){
            state = XF::ST_WAIT_CD;
        }
        if(ev->getID() == XF::evDone){
            state = XF::ST_WAIT;
        }
        break;
    case XF::ST_WAIT_CD:
        if(ev->getID() == XF::evTimeout){
            state = XF::ST_COUNTDOWN;
        }
        break;
    case XF::ST_WAIT_BEX:
        if(ev->getID() == XF::evTimeout){
            state = XF::ST_BEX;
        }
        break;
    case XF::ST_BEX:
        if(ev->getID() == XF::evWait){
            state = XF::ST_WAIT_BEX;
        }
        if(ev->getID() == XF::evDone){
            state = XF::ST_WAIT;
        }
        break;
    }

    if (oldState != state)
    {
        //action switch
        XFEvent* ev = new XFEvent();

        switch (state)
        {
        case XF::ST_WAIT:
            break;
        case XF::ST_ANIM1:
            if(anim1->isDone()){
                anim1->setIsDone(false);
                ev->setID(XF::evDone);
                ev->setTarget(this);
                XF::getInstance().pushEvent(ev);
            }else{
                anim1->animate();
                ev->setID(XF::evWait);
                ev->setTarget(this);
                XF::getInstance().pushEvent(ev);
            }
            break;
        case XF::ST_WAIT1:
        case XF::ST_WAIT_CD:
        case XF::ST_WAIT_BEX:
            ev->setID(XF::evTimeout);
            ev->setTarget(this);
            ev->setDelay(valueTimer);
            XF::getInstance().pushEvent(ev);
            break;
        case XF::ST_COUNTDOWN:
            if(countDown->isDone()){
                countDown->setIsDone(false);
                ev->setID(XF::evDone);
                ev->setTarget(this);
                XF::getInstance().pushEvent(ev);
            }else{
                countDown->animate();
                ev->setID(XF::evWait);
                ev->setTarget(this);
                XF::getInstance().pushEvent(ev);
            }
            break;
        case XF::ST_BEX:
            if(bex->isDone()){
                bex->setIsDone(false);
                ev->setID(XF::evDone);
                ev->setTarget(this);
                XF::getInstance().pushEvent(ev);
            }else{
                bex->animate();
                ev->setID(XF::evWait);
                ev->setTarget(this);
                XF::getInstance().pushEvent(ev);
            }
            break;
        }
        retval = true;
    }
    return retval;
}

//Modifie the value of the timer, used principaly by
//all the anime classes
void Controller::setValueTimer(int time){
    valueTimer = time;
}
