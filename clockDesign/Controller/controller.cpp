#include "controller.h"

Controller::Controller()
{
    digClock = new DigitalClock(this);
    anim1 = new Animation1(this);
    countDown = new Countdown(this);
}

void Controller::initialize()
{
    state = XF::ST_WAIT;
}

//void Controller::initRelations(Data* data, View* view)
void Controller::initRelations(Data* data)
{
    this->pData = data;
    //this->pView = view;
}

bool Controller::processEvent(XFEvent *ev){
    bool retval = false;
    XF::CSTATE oldState = state;

    //Exit
    if(ev->getID() == XF::evExit){
        //View::stop();
        pView->stop();
    }

    //transition switch
    switch (state)
    {
    case XF::ST_WAIT:
        if (ev->getID() == XF::evAnim1)
        {
            state = XF::ST_ANIM1;
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
        case XF::ST_WAIT1:
            ev->setID(XF::evTimeout);
            ev->setTarget(this);
            ev->setDelay(valueTimer);
            XF::getInstance().pushEvent(ev);
        }
        retval = true;
    }
    return retval;
}

//Modifie the value of the timer, used principaly by
//the anime classes
void Controller::setValueTimer(int time){
    valueTimer = time;
}
